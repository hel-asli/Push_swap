CC = cc
CFLGAS = -Wall -Wextra -Werror
M_SRCSS = main.c utils/utils.c utils/ft_split.c utils/parsing_utils.c utils/operations.c utils/stack_utils.c \
 			utils/parsing_helper.c

M_OBJS = $(M_SRCSS:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLGAS) $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLGAS) -c $< -o $@

clean :
	$(RM) $(M_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
