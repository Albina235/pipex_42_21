#include "pipex.h"

char	*find_paths(char **env)
{
	while (ft_strncmp("PATH", env, 4))
		env++;
	return (*env + 5);
}

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
	free(all->cmd); // free(all->cmd_paths) ?????????
}

static char	*get_cmd(char **cmd_paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0) // check if there is a file in the current directory, that is, if such a command exist
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
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
