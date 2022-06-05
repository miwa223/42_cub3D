NAME			= cub3D
CC				= cc
INCLUDES		= -I./includes
CFLAGS			= -Wall -Werror -Wextra -MMD -MP $(INCLUDES)

SRC_DIR			= srcs/
SRC_FILE		:= main.c \
				draw_wall.c \
				error.c \
				game.c \
				init_player.c \
				mlx_utils.c \
				set_data.c \
				vector.c \
				wall_utils.c
SRC				= $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_DIR			= obj/
OBJ				= $(addprefix $(OBJ_DIR), $(SRC_FILE:%.c=%.o))
DEPEND			= $(OBJ:%.o=%.d)

LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a

UNAME			= $(shell uname)
ifeq ($(UNAME), Darwin)
	MLXFLAG = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	ifeq ($(UNAME), Linux)
		MLXFLAG = -Imlx -lXext -lX11
	endif
endif
MLX_DIR		= mlx/
MLX_NAME	= libmlx_$(UNAME).a


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L. $(LIBFT_DIR)$(LIBFT_NAME) $(MLXFLAG) -L. $(MLX_DIR)$(MLX_NAME) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	@if [ -d $(OBJ_DIR) ]; then rm -r $(OBJ_DIR) ; fi

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus: all

-include $(DEPEND)
.PHONY: all clean fclean re bonus
