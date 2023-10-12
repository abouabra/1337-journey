SRC= ft_printf.c scan_flags.c general_func.c ft_printf_utils.c ft_printf_bonus_utils.c printf_p.c printf_c.c printf_s.c ft_libft.c

OBJS=$(SRC:.c=.o)
AR=ar -rcs
NAME=libftprintf.a
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

%.o:%.c
	@$(CC) -Wall -Wextra -Werror -c $<

bonus: fclean all

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o libftprintf.a

re:fclean all

.PHONY: all clean fclean re