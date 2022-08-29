NAME1		= server

NAME2		= client

HEADER		= minitalk.h

SRCS		= client.c \
				server.c

OBJS		= $(SRCS:.c=.o)

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME1) $(NAME2)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re