# include "pipex.h"

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
	all.path = find_path(env);
	all.cmd_paths = ft_split(all.path, ':');
	all.id1 = fork();
	if (all.id1 == 0)
		first_child(all, argv, env);
	if (all.id1 != 0)
		all.id2 = fork();
	if (all.id2 == 0)
		second_child(all, argv. env);

}
