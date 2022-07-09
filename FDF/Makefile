UNAME := $(shell uname)
NAME = fdf
BONUS_NAME = fdf_bonus
CFLAGS = -Wall -Wextra -Werror
SRC = main.c input_check.c parse_map.c draw.c handle_keys.c
SRC_BONUS = main_bonus.c input_check_bonus.c parse_map_bonus.c draw_bonus.c handle_keys_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER = fdf.h
HEADER_BONUS = fdf_bonus.h

%.o: %.c	${HEADER} ${HEADER_BONUS}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
############################# IF LINUX #############################
ifeq ($(UNAME), Linux)
FLAGS = -L/usr/include/X11/extensions -lX11 -lXext -lm
INCL = libft/libft.a minilibx/libmlx_Linux.a

$(NAME): $(OBJ)
	@make -C libft / all
	@make -C minilibx / libmlx_Linux.a
	gcc $(CFLAGS) $(OBJ) $(INCL) $(FLAGS) -o $(NAME)
$(BONUS_NAME): $(OBJ_BONUS)
	@make -C libft / all
	@make -C minilibx / libmlx_Linux.a
	gcc $(CFLAGS) $(OBJ_BONUS) $(INCL) $(FLAGS) -o $(BONUS_NAME)
all: $(NAME)
bonus: $(BONUS_NAME)
clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	@make -C libft/ clean
	@make -C minilibx/ clean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C libft / fclean
re: fclean all
.PHONY: all clean fclean re

####################### NOT MY LOVELY LINUX ########################
else
FLAGS = -framework OpenGL -framework AppKit -lm
INCL = libft/libft.a minilibx_macos/libmlx.a

$(NAME): $(OBJ)
	@make -C libft / all
	@make -C minilibx_macos / libmlx.a
	gcc $(CFLAGS) $(OBJ) $(INCL) $(FLAGS) -o $(NAME)
$(BONUS_NAME): $(OBJ_BONUS)
	@make -C libft / all
	@make -C minilibx_macos / libmlx.a
	gcc $(CFLAGS) $(OBJ_BONUS) $(INCL) $(FLAGS) -o $(BONUS_NAME)
all: $(NAME)
bonus: $(BONUS_NAME)
clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C libft / fclean
re: fclean all
.PHONY: all clean fclean re
endif