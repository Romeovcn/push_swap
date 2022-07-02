SRCS	= push_swap.c get_lst.c operations.c utils.c calculate_move.c

LIB		= ./libft/libft.a

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	make -C ./libft
	$(CC) $(SRCS) $(LIB)

all:	${NAME}

clean:
	rm -f ${OBJS}
	make -C ./libft clean

fclean:
	rm -vf ${NAME} ${OBJS}
	make -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re bonus