OBJ_DIR = obj

TEST_NAME = tester
TEST_SRC = tests/valid_tests.c tests/invalid_tests.c tests/exec_program.c \
		tests/check_invalid.c tests/run_cub3d.c tests/check_valid.c
TEST_OBJ = $(TEST_SRC:%.c=$(OBJ_DIR)/%.o)
TEST_DEP = $(TEST_SRC:%.c=$(OBJ_DIR)/%.d)
TEST_CFLAGS = -MMD
TEST_LIBS = -lcriterion

OBJ = $(SRC:%.c=obj/%.o)
DEP = $(SRC:%.c=obj/%.d)

all: test

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/tests/%.o: tests/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(TEST_CFLAGS) -c $< -o $@

$(TEST_NAME): $(TEST_OBJ)
	@$(CC) $(TEST_OBJ) -o $(TEST_NAME) $(TEST_LIBS)

test: $(TEST_NAME)

clean:
	@rm -f $(TEST_OBJ) $(TEST_DEP)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(TEST_DEP)