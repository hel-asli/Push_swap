CC = cc
CFLGAS = -Wall -Wextra -Werror -fsanitize=address -g
M_SRCSS = Mandatory/main.c Mandatory/utils/utils.c Mandatory/utils/ft_split.c \
		Mandatory/utils/parsing_utils.c Mandatory/utils/operations.c Mandatory/utils/operations2.c Mandatory/utils/stack_utils.c \
 		Mandatory/utils/parsing_helper.c Mandatory/utils/algo_helper.c Mandatory/utils/sorting_helper.c Mandatory/utils/operations2.c
B_SRCS = Bonus/main.c Bonus/utils_bonus/ft_split_bonus.c Bonus/utils_bonus/operations_bonus.c Bonus/utils_bonus/parsing_utils_bonus.c Bonus/utils_bonus/parsing_helper_bonus.c \
		Bonus/utils_bonus/stack_utils_bonus.c Bonus/utils_bonus/utils.c Bonus/gnl/get_next_line.c Bonus/gnl/get_next_line_utils.c \
		Bonus/utils_bonus/operations_bonus2.c Bonus/utils_bonus/checker_helper.c


B_OBJS = $(B_SRCS:.c=.o)
M_OBJS = $(M_SRCSS:.c=.o)

NAME = push_swap
B_NAME = checker

all : $(NAME)

bonus : $(B_NAME)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLGAS) $^ -o $@

Mandatory/%.o : Mandatory/%.c Mandatory/push_swap.h
	$(CC) $(CFLGAS) -c $< -o $@

$(B_NAME) : $(B_OBJS)
	$(CC) $(CFLGAS) $^ -o $@

Bonus/%.o : Bonus/%.c Bonus/push_swap_bonus.h
	$(CC) $(CFLGAS) -c $< -o $@

clean :
	$(RM) $(M_OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME) $(B_NAME)

re : fclean all bonus

.Phony : clean