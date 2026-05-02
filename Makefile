NAME = cub3D

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MLX_DIR = libraries/mlx
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

SOURCES = src/main.c\
		  src/game.c\
		  src/graphics/init_mlx.c\
		  src/graphics/render.c\
		  src/graphics/textures.c\
		  src/raycasting/dda.c\
		  src/raycasting/dda_helper.c\
		  src/movement/movement.c\
		  src/movement/movement_helper.c\
		  src/parsing/parse.c\
		  src/parsing/paths.c\
		  src/parsing/color.c\
		  src/parsing/map.c\
		  src/parsing/helper.c\
		  src/parsing/floodFill.c\
		  src/utility/helpers.c

HEADERS = includes/cub3D.h \
		  includes/game.h \
		  includes/map.h \
		  includes/vec.h \
		  includes/color.h

OBJ_DIR = objects/
OBJS = $(SOURCES:%.c=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(MLX_DIR)/libmlx.a $(LIBFT) $(NAME)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@

$(OBJ_DIR)%.o: %.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -MMD -MP -c $< -o $@

run: all
	./$(NAME)

runval: CFLAGS := -Wall -Wextra -Werror -g
runval: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

runsan: CFLAGS := -g -fsanitize=address,leak,undefined,bounds,float-divide-by-zero
runsan: re
	./$(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)
