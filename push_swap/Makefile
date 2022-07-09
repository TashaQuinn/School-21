NAME = push_swap
BNAME = checker
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
SRC = main.c libft.c ft_atoi.c ft_split.c error_handling.c \
		stack_sort.c utils.c utils2.c utils3.c utils4.c \
		operations.c operations2.c operations3.c
SRCB = checker.c checker_utils.c checker_operations.c \
		checker_libft.c libft.c ft_atoi.c ft_split.c \
		error_handling.c operations.c operations2.c \
		operations3.c stack_sort.c utils.c utils2.c \
		utils3.c utils4.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
HEADER = push_swap.h

%.o: %.c ${HEADER}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@
		
$(BNAME): $(OBJB)
		$(CC) $(CFLAGS) $^ -o $@
		
all: $(NAME)
bonus: $(BNAME)
clean:
		$(RM) $(OBJ) $(OBJB)
fclean: clean
		$(RM) $(NAME) $(BNAME)
re: fclean all
.PHONY: all clean fclean re bonus