CC = cc
CFLGAS = -Wall -Wextra -Werror
M_SRCSS = main.c utils/ft_atol.c utils/ft_putstr_fd.c utils/ft_split.c
M_OBJS = $(M_SRCSS:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLGAS) -g $^ -o $@

%.o : %.c push_swap.h
	$(CC) $(CFLGAS) -c -g $< -o $@

clean :
	$(RM) $(M_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
