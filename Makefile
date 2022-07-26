SRCS_DIR	= srcs

OBJS_DIR	= objs

SRCSBONUS_DIR	= srcs_bonus

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

OBJS	= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS}}

OBJS_BONUS	= ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_BONUS}}

HEADERS	= push_swap.h

HEADERS_BONUS	= push_swap_bonus.h

NAME	= push_swap

NAME_BONUS	= checker_bonus

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra                     

# -- RULES -- #

${NAME}:	${OBJS_DIR} ${OBJS} ${HEADERS}
	@make -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@echo "Push_swap compiled !"
	@echo ----------------------------

all:	${NAME}

$(OBJS_DIR):
	@mkdir ${OBJS_DIR}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: ${SRCSBONUS_DIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@make clean -C ./libft
	@rm -rf ${OBJS_DIR}

fclean:	clean
	@make fclean -C ./libft
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: all ${OBJS_BONUS} ${HEADERS_BONUS}
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB} -o ${NAME_BONUS}

.PHONY:	all clean fclean re