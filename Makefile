SRCS	=	push_swap.c \
			get_stack.c \
			operations.c \
			operations_part_2.c \
			utils.c \
			calculate_move.c \
			move_ordered_b_to_a.c \
			do_op.c \
			sort_big_stack.c \
			sort_small_stack.c \
			check_error.c\

LIB		= ./libft/libft.a

OBJS	= ${SRCS:.c=.o}

DEPS	= push_swap.h

NAME	= push_swap

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra                     

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}  ${DEPS}
	@make -C ./libft
	@$(CC) $(OBJS) $(LIB) -o ${NAME}
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