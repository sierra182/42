CC = gcc
NAME = a.out
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
SOURCES = test_ft_strtrim.c
LIBFTDIR = ./libft
LIBFTPATH = ./libft/libft.a

.PHONY: all libft clean fclean re

all: libft $(NAME) 

libft:
	$(MAKE) -C $(LIBFTDIR)

$(NAME) : $(SOURCES) $(LIBFTPATH)
	$(CC) $(CFLAGS) $< $(LDFLAGS) 

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
