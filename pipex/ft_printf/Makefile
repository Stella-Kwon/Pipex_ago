.SUFFIXES = .c .o

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_hex.c ft_printf_str.c ft_printf_d_i.c ft_printf_p.c ft_printf_ul.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

INCLUDE = -I ft_printf.h

all: subsystem $(NAME)

subsystem:

	cd libft && $(MAKE) && make bonus

$(NAME):
	cp ./libft/libft.a ./$(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS)
	ar -rus $@ $(OBJS)

clean:
	make -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
