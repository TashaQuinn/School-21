CC = cc
CFLAGS = -Wextra -Wall -Werror -c

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_dispatcher.c \
	  ft_print_char.c ft_print_percent.c ft_print_nbr.c \
	  ft_print_unsigned_nbr.c ft_print_str.c ft_print_hex.c\
	  ft_print_ptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC)
	$(AR) rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re