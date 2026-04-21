NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = mlx
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

SOURCES = main.c \
		  parsePaths.c \
		  parseMap.c \
		  memory.c \
		  floodFill.c \
		  helpers.c \

HEADERS = cub3D.h game.h map.h

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
