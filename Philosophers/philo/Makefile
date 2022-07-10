NAME = philo
HEADER = philo.h
CC = cc
FLAGS = -Wall -Werror -Wextra -pthread
RM = rm -f
SRC = main.c libft.c check_input.c deal_w_time.c init_structs.c \
			monitor.c case_of_one.c start_threads.c stuff_to_do.c
OBJ = $(SRC:.c=.o)
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re