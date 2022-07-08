SRCSDIR	= srcs

OBJSDIR	= objs

SRCSBONUSDIR	= srcs_bonus

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

SRCS_BONUS	=	checker_bonus.c \

LIB		= ./libft/libft.a

OBJS	= ${patsubst %.c,${OBJSDIR}/%.o,${SRCS}}

OBJS_BONUS	= ${patsubst %.c,${OBJSDIR}/%.o,${SRCS_BONUS}}

HEADERS	= push_swap.h

NAME	= push_swap

NAME_BONUS	= checker_bonus

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra                     

# -- RULES -- #

${NAME}:	${OBJSDIR} ${OBJS} ${HEADERS}
	@make -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@echo "Push_swap compiled !"
	@echo ----------------------------

all:	${NAME}

$(OBJSDIR):
	@mkdir ${OBJSDIR}

${OBJSDIR}/%.o: ${SRCSDIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@rm -rf ${OBJSDIR}

fclean:	clean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: all ${OBJS_BONUS}
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB} -o ${NAME_BONUS}

.PHONY:	all clean fclean re