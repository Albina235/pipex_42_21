# include "pipex.h"

void	message_error(char *str)
{
	perror(str);
	exit (1);
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
