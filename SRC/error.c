# include "pipex.h"

void	message_error(char *str)
{
	perror(str);
	exit (1);
}
