CC = cc
CFLGAS = -Wall -Wextra -Werror
M_SRCSS = Mandatory/main.c Mandatory/utils/utils.c Mandatory/utils/ft_split.c \
		Mandatory/utils/parsing_utils.c Mandatory/utils/operations.c Mandatory/utils/stack_utils.c \
 		Mandatory/utils/parsing_helper.c Mandatory/utils/algo_helper.c

M_OBJS = $(M_SRCSS:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(M_OBJS)
	@echo "make Mandatory"
	@$(CC) $(CFLGAS) $^ -o $@

Mandatory/%.o : Mandatory/%.c Mandatory/push_swap.h
	@echo "compile $< to $@"
	@$(CC) $(CFLGAS) -c $< -o $@

clean :
	$(RM) $(M_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
