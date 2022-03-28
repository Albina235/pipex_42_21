NAME = pipex

SRCS = src/error.c	src/pipex.c	src/utils.c\
		libft/ft_split.c	libft/ft_strncmp.c	libft/ft_strjoin.c

OBJ = ${SRCS:%.c=%.o}

CC = gcc -Wall -Werror -Wextra

RM = rm -rf

HEADER = pipex.h

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

.PHONY: all clean fclean re

all:	${NAME}

${NAME}:	${OBJ}
		@echo	"$(GREEN)Compilation of ${NAME}$(DEFAULT)"
		@${CC} ${OBJ} -o ${NAME}
		@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

%.o: %.c ${HEADER}
		@${CC} -c $< -o $@

clean:
		@rm -f ${OBJ}
		@echo "${YELLOW}\nCleaning done\n$(DEFAULT)"

fclean:	clean
		@rm -f ${NAME}
		@echo "${YELLOW}All files were deleted\n$(DEFAULT)"

re:	fclean all
