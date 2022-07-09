NAME = pipex
BNAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = main.c utils.c libft.c libft2.c ft_split.c
SRCB =  main_bonus.c utils_bonus.c libft_bonus.c libft2_bonus.c ft_split_bonus.c
HEADER = pipex.h
HEADER_BONUS = pipex_bonus.h
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

%.o: %.c	${HEADER} ${HEADER_BONUS}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

$(BNAME): $(OBJB)
		$(CC) $(CFLAGS) $^ -o $@
		
bonus: $(BNAME)

all: $(NAME)

clean: 
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(BNAME)
	
re: fclean all
.PHONY: all clean fclean re bonus