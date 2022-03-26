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

typedef struct s_pipex
{
	pid_t	id1;
	pid_t	id2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	message_error(char *str);
void	first_child(t_pipex all, char **argv, char **env);
void	second_child(t_pipex all, char **argv, char **env);
void	child_free(t_pipex *all);
void	parent_free(t_pipex *all);
char	*find_paths(char **env);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
