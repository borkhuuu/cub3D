NAME = cub3D

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = mlx
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SOURCES = main.cpp

HEADERS =

OBJ_DIR = objects/
OBJS = $(SOURCES:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(MLX_DIR)/libmlx.a $(NAME)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(MLX_FLAGS) -o $@

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(MLX_DIR) -MMD -MP -c $< -o $@

run: all
	./$(NAME)

runval: CXXFLAGS := -Wall -Wextra -Werror -pedantic -g
runval: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

runsan: CXXFLAGS := -g -fsanitize=address,leak,undefined,bounds,float-divide-by-zero
runsan: re
	./$(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(MLX_DIR) clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)