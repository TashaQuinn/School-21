NAME = philo_bonus
HEADER = philo_bonus.h
CC = cc
FLAGS = -Wall -Werror -Wextra -pthread
RM = rm -f
SRC = main_bonus.c libft_bonus.c check_input_bonus.c deal_w_time_bonus.c \
			monitor_bonus.c start_threads_bonus.c stuff_to_do_bonus.c \
			init_structs_bonus.c
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