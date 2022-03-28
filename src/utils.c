/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:15:56 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/28 10:15:57 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **cmd_paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
}

void	second_child(t_pipex all, char **argv, char **env)
{
	dup2(all.fd[0], 0);
	close(all.fd[1]);
	dup2(all.outfile, 1);
	all.cmd_args = ft_split(argv[3], ' ');
	all.cmd = get_cmd(all.cmd_paths, all.cmd_args[0]);
	if (!all.cmd)
	{
		child_free(&all);
		message_error("Command error\n");
	}
	execve(all.cmd, all.cmd_args, env);
	exit(0);
}

void	first_child(t_pipex all, char **argv, char **env)
{
	dup2(all.fd[1], 1);
	close(all.fd[0]);
	dup2(all.infile, 0);
	all.cmd_args = ft_split(argv[2], ' ');
	all.cmd = get_cmd(all.cmd_paths, all.cmd_args[0]);
	if (!all.cmd)
	{
		child_free(&all);
		message_error("Command error\n");
	}
	execve(all.cmd, all.cmd_args, env);
}
