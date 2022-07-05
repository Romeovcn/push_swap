SRCS	=	push_swap.c get_lst.c operations.c \
			utils.c calculate_move.c move_ordered_b_to_a.c \
			do_op.c sort_big_stack.c sort_small_stack.c \

LIB		= ./libft/libft.a

OBJS	= ${SRCS:.c=.o}

DEPS	= push_swap.h

NAME	= so_long

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}  ${DEPS}
	@make -C ./libft
	@$(CC) $(SRCS) $(LIB) -o push_swap
	@echo ----------------------------

all:	${NAME}

clean:
	@rm -f ${OBJS}
	@make -C ./libft clean

fclean:
	@rm -vf ${NAME} ${OBJS}
	@make -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re bonus