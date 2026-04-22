#include "tester.h"

t_result	run_cub3d(char **argv)
{
	t_result	res;

	bzero(&res, sizeof(t_result));
	if (exec_program(&res, argv) == -1)
		cr_assert_fail("System error: couldn't execute test");
	return (res);
}

Test(invalid, wrong_xpm_extension)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/invalid_xpm_extension.cub", NULL};
	res = run_cub3d(argv);
	
	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
         	    "stderr does not start with 'Error\\n'");
	printf("Test: wrong_xpm_extension passed ✅\n");
}

Test(invalid, file_doesnt_exist)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "no.cub", NULL};
	res = run_cub3d(argv);
	
	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: file_doesnt_exist passed ✅\n");
}

Test(invalid, empty_file)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/empty.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: empty_file passed ✅\n");
}

Test(invalid, no_map)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/no_map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: no_map passed ✅\n");
}

Test(cub3d, wrong_extension_cubb)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/invalid_extension.cubbb", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: wrong_extension_cubb passed ✅\n");
}

Test(invalid, no_args)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: no_args passed ✅\n");
}

Test(invalid, empty_arg)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: empty_arg passed ✅\n");
}

Test(invalid, hidden_file_in_folder)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: hidden_file_in_folder passed ✅\n");
}

Test(invalid, hidden_file)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, ".cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: hidden_file passed ✅\n");
}

Test(invalid, empty_xpm_file)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/empty_xpm_file.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: empty_xpm_file passed ✅\n");
}

Test(invalid, linked_hidden_file_xpm)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/link_xpm_file.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: linked_hidden_file_xpm passed ✅\n");
}

Test(invalid, invalid_char_in_map)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/invalid_char_in_map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: invalid_char_in_map passed ✅\n");
}

Test(invalid, wrong_extension_txt)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/invalid_extension.txt", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: wrong_extension_txt passed ✅\n");
}

Test(invalid, misplaced_info)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/misplaced_info.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: misplaced_info passed ✅\n");
}

Test(invalid, missing_texture)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/missing_texture.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: missing_texture passed ✅\n");
}

Test(invalid, only_map)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/only_map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: only_map passed ✅\n");
}

Test(invalid, player_out_of_map)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/player_out_of_map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: player_out_of_map passed ✅\n");
}

Test(invalid, random_content)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/random_content.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: random_content passed ✅\n");
}

Test(invalid, space_in_colour)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/space_in_color.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: space_in_colour passed ✅\n");
}

Test(invalid, space_in_map)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/space_in_map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: space_in_map passed ✅\n");
}

Test(invalid, multiple_maps)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/multiple_maps.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: multiple_maps passed ✅\n");
}

Test(invalid, random_word_arg)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "lalalala", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: random_word_arg passed ✅\n");
}

Test(invalid, multiple_map_args)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/valid/map.cub", "maps/valid/map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: multiple_map_args passed ✅\n");
}

Test(invalid, multiple_map_args_in_one_arg)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/valid/map.cub maps/valid/map.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: multiple_map_args_in_one_arg passed ✅\n");
}

Test(invalid, spaces_in_xpm_file)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/spaces_in_xpm_file.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: spaces_in_xpm_file passed ✅\n");
}

Test(invalid, extra_commas_in_colour)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/extra_commas_in_colour.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: extra_commas_in_colour passed ✅\n");
}

Test(invalid, out_of_range_rgb_value)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/out_of_range_rgb_value.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: out_of_range_rgb_value passed ✅\n");
}

Test(invalid, empty_rgb_value)
{
	t_result	res;
	char *argv[] = {VAL, FLAG1, FLAG2, FLAG3, FLAG4, FLAG5, PROG, "maps/invalid/empty_rgb_value.cub", NULL};
	res = run_cub3d(argv);

	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
              "stderr does not start with 'Error\\n'");
	printf("Test: empty_rgb_value passed ✅\n");
}
