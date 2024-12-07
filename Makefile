CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = philo
POSIX = -pthread -fsanitize=thread
SRC = src/philo.c src/libft.c src/free.c src/libft_2.c src/dining.c src/init.c src/philo_utils.c
OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(POSIX)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


