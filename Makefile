SRCSDIR	= srcs

OBJSDIR	= objs

SRCSBONUSDIR	= srcs_bonus

SRCS	=	push_swap.c \
			get_stack.c \
			operations_stack_a.c \
			operations_stack_b.c \
			operations_reverse.c \
			utils.c \
			get_best_big_stack.c \
			get_best_big_stack_part_2.c \
			get_best_small_stack.c \
			do_op.c \
			sort_big_stack.c \
			sort_small_stack.c \
			sort_medium_stack.c \
			check_error.c \
			get_data.c \

SRCS_BONUS	=	checker_bonus.c \
				get_stack_bonus.c \
				check_error_bonus.c \
				utils_bonus.c \
				operations_stack_a_bonus.c \
				operations_stack_b_bonus.c \
				operations_reverse_bonus.c \

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
	@${CC} ${OBJS} ${LIB} -o ${NAME}
	@echo "Push_swap compiled !"
	@echo ----------------------------

all:	${NAME}

$(OBJSDIR):
	@mkdir ${OBJSDIR}

${OBJSDIR}/%.o: ${SRCSDIR}/%.c
	@${CC} -I. -c $< -o $@

${OBJSDIR}/%.o: ${SRCSBONUSDIR}/%.c
	@${CC} -I. -c $< -o $@

clean:
	@make clean -C ./libft
	@rm -rf ${OBJSDIR}

fclean:	clean
	@make fclean -C ./libft
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: all ${OBJS_BONUS}
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB} -o ${NAME_BONUS}

.PHONY:	all clean fclean re