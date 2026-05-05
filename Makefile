NAME = cub3D

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MLX_DIR = libraries/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

SOURCES = mandatory/src/main.c\
		  mandatory/src/game.c\
		  mandatory/src/graphics/init_mlx.c\
		  mandatory/src/graphics/render.c\
		  mandatory/src/graphics/textures.c\
		  mandatory/src/raycasting/dda.c\
		  mandatory/src/raycasting/dda_helper.c\
		  mandatory/src/movement/movement.c\
		  mandatory/src/movement/movement_helper.c\
		  mandatory/src/parsing/parse.c\
		  mandatory/src/parsing/paths.c\
		  mandatory/src/parsing/color.c\
		  mandatory/src/parsing/map.c\
		  mandatory/src/parsing/helper.c\
		  mandatory/src/parsing/floodFill.c\
		  mandatory/src/utility/helpers.c\
		  mandatory/src/utility/parse_helpers.c\
		  mandatory/src/utility/setup.c\

HEADERS = mandatory/includes/cub3D.h \
		  mandatory/includes/game.h \
		  mandatory/includes/map.h \
		  mandatory/includes/vec.h \
		  mandatory/includes/color.h

OBJ_DIR = objects/
OBJS = $(SOURCES:%.c=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)


BONUS_SOURCES = bonus/src/main_bonus.c\
		  bonus/src/game_bonus.c\
		  bonus/src/graphics/init_mlx_bonus.c\
		  bonus/src/graphics/render_bonus.c\
		  bonus/src/graphics/textures_bonus.c\
		  bonus/src/raycasting/dda_bonus.c\
		  bonus/src/raycasting/dda_helper_bonus.c\
		  bonus/src/movement/movement_bonus.c\
		  bonus/src/movement/movement_helper_bonus.c\
		  bonus/src/parsing/parse_bonus.c\
		  bonus/src/parsing/paths_bonus.c\
		  bonus/src/parsing/color_bonus.c\
		  bonus/src/parsing/map_bonus.c\
		  bonus/src/parsing/helper_bonus.c\
		  bonus/src/parsing/floodFill_bonus.c\
		  bonus/src/utility/helpers_bonus.c\
		  bonus/src/utility/parse_helpers_bonus.c\

HEADERS = bonus/includes/cub3D_bonus.h \
		  bonus/includes/game_bonus.h \
		  bonus/includes/map_bonus.h \
		  bonus/includes/vec_bonus.h \
		  bonus/includes/color_bonus.h

BONUS_OBJ_DIR = bonus_objects/
BONUS_OBJS = $(BONUS_SOURCES:%.c=$(BONUS_OBJ_DIR)%.o)
BONUS_DEPS = $(BONUS_OBJS:.o=.d)

all: $(NAME)

$(NAME): .mandatory_mode

.mandatory_mode: $(OBJS) $(MLX) $(LIBFT)
	@rm -f .bonus_mode
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@touch .mandatory_mode

bonus: .bonus_mode

.bonus_mode: $(MLX) $(LIBFT) $(BONUS_OBJS)
	@rm -f .mandatory_mode
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@touch .bonus_mode

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)


$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -MMD -MP -c $< -o $@

$(BONUS_OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -MMD -MP -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	@rm -f .bonus_mode .mandatory_mode
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS) -include $(BONUS_DEPS)
