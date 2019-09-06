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
SRC_NAME = 	main.c parcing.c error.c

# mlx library
MLX        = ./miniLibx_macos/
MLX_LIB    = $(addprefix $(MLX),mlx.a)
MLX_INC    = -I ./miniLibx_macos
MLX_LNK    = -L ./miniLibx_macos -l mlx -framework OpenGL -framework AppKit

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

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/wolf.h | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(FT_INC) $(MLX_INC) -I $(INC_PATH)  -o $@ -c $<
	@printf "$(BLUE)>>Compiling $(WITHE) $< $(END)"

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -o $(NAME)
	@printf "$(YELLOW)$(NAME)$(END)		$(GREEN)[compiled]$(END)\n"


clean:
	@rm -rf $(OBJ_PATH)
	@cd libft && $(MAKE) clean
	@cd miniLibx_macos && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean
	@cd miniLibx_macos && $(MAKE) fclean

re: fclean all
