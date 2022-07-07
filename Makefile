SRCSDIR	= srcs

OBJSDIR	= objs

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
			check_error.c \

LIB		= ./libft/libft.a

OBJS	= ${patsubst %.c,${OBJSDIR}/%.o,${SRCS}}

HEADERS	= push_swap.h

NAME	= push_swap

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra                     

${NAME}:	$(OBJSDIR) ${OBJS} ${HEADERS}
	@make -C ./libft
	@$(CC) $(OBJS) $(LIB) -o ${NAME}
	@echo "Push_swap compiled !"
	@echo ----------------------------

all:	${NAME}

$(OBJSDIR):
	@mkdir ${OBJSDIR}

${OBJSDIR}/%.o: ${SRCSDIR}/%.c
	@${CC} -I. -c $< -o $@

clean:
	@rm -rf ${OBJS} $(OBJSDIR)

fclean:	clean
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re