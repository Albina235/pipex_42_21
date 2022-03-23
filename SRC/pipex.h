#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	pid_t	id1;
	pid_t	id_2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	message_error(char *str);
char	*find_paths(char **env);

#endif
