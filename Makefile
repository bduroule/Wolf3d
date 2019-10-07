NAME = wolf3d

#Color
BLUE 	= \033[2K\r\033[36m
GREEN 	= \e[92m
WITHE 	= \033[37m
YELLOW	= \033[33m
END 	= \033[0m

#Dir
OBJ_PATH = ./obj/
SRC_PATH = ./srcs/
INC_PATH = ./include/

#file
SRC_NAME = 	main.c parcing.c error.c display.c algo.c mlx_draw.c raycasting.c hook_key.c hook_mouse.c

# mlx library
MLX        = ./minilibx_macos/
MLX_LIB    = $(addprefix $(MLX),mlx.a)
MLX_INC    = -I ./minilibx_macos
MLX_LNK    = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

# ft library
FT        = ./libft/
FT_LIB    = $(addprefix $(FT),libft.a)
FT_INC    = -I ./libft
FT_LNK    = -L ./libft -l ft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

#compil
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INC_HDR) -O3

all: run_libs create_dirs $(NAME)

run_libs:
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos

create_dirs:
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -o $(NAME)
	@printf "$(YELLOW)$(NAME)$(END)		$(GREEN)[compiled]$(END)\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/wolf.h libft/libft.a | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(FT_INC) $(MLX_INC) -I $(INC_PATH)  -o $@ -c $<
	@printf "$(BLUE)>>Compiling $(WITHE) $< $(END)"

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C ./libft/ clean
	@$(MAKE) -C ./minilibx_macos/ clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft/ fclean

re: fclean all
