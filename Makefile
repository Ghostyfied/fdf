NAME = fdf

CC = cc

GRAPHICS_FLAGS+= -framework OpenGL -framework AppKit

SRC_PATH = src/
INC_PATH = includes/
OBJ_PATH = obj/
LIBFT_PATH = includes/libft/
MLX_PATH = includes/minilibx/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_MLX = $(addprefix -I, $(MLX_PATH))
INC_LFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

SRC_NAME = 	main.c extras.c initialize.c read_and_check_input.c get_colours.c \
			draw_map1.c get_coor.c
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) -g -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(GRAPHICS_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC) $(INC_MLX) $(INC_LFT) -o $@ -c $< 

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	
re: fclean all