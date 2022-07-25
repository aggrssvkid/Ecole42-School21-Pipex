
NAME = pipex

SRCS = find_ways.c del_matrix.c multiply_func.c get_next_line.c here_doc.c multiply_doc.c\
		append.c ft_split.c ft_strdup.c ft_strlen.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c\
		ft_strtrim.c ft_strrchr.c pipex.c

OBJS = $(SRCS:%.c=%.o)
HEADER = libpipex.h
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	 $(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re