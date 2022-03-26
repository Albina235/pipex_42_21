# include "pipex.h"

char	*find_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	all;

	if (argc != 5)
		message_error("Invalid number of arguments.\n");
	all.infile = open(argv[1], O_RDONLY);
	if (all.infile < 0)
		message_error("Inputfile error\n");
	all.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 00644);
	if (all.outfile < 0)
		message_error("Outputfile error\n");
	if (pipe(all.fd) < 0)
		message_error("Pipe error\n");
	all.paths = find_paths(env); /*find all command files*/
	all.cmd_paths = ft_split(all.paths, ':'); //all commad path in 2_d array
	all.id1 = fork(); //first branching
	if (all.id1 == 0)
		first_child(all, argv, env);
	all.id2 = fork();
	if (all.id2 == 0)
		second_child(all, argv, env);
	close_pipes(&all);
	waitpid(all.id1, NULL, 0);
	waitpid(all.id2, NULL, 0);
	parent_free(&all);
	return (0);
}
