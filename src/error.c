/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:12:37 by evalorie          #+#    #+#             */
/*   Updated: 2022/03/28 10:12:39 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_free(t_pipex *all)
{
	int	i;

	i = -1;
	close(all->infile);
	close(all->outfile);
	while (all->cmd_paths[++i])
		free(all->cmd_paths[i]);
	free(all->cmd_paths);
}

void	child_free(t_pipex *all)
{
	int	i;

	i = -1;
	while (all->cmd_args[++i])
		free(all->cmd_args[i]);
	free(all->cmd_args);
	free(all->cmd);
}
