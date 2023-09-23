CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SOURCES = $(filter-out %_bonus.c, $(wildcard *.c))
SOURCES_BONUS = ft_lstnew_bonus.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $^

bonus: $(OBJECTS_BONUS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
