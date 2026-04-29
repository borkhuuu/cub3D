#include "tester.h"

Test(invalid, wrong_xpm_extension)
{
	t_result	res;
	char *args[] = {"maps/invalid/invalid_xpm_extension.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: wrong_xpm_extension passed ✅\n");
}

Test(invalid, file_doesnt_exist)
{
	t_result	res;
	char *args[] = {"no.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: file_doesnt_exist passed ✅\n");
}

Test(invalid, empty_file)
{
	t_result	res;
	char *args[] = {"maps/invalid/empty.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: empty_file passed ✅\n");
}

Test(invalid, no_map)
{
	t_result	res;
	char *args[] = {"maps/invalid/no_map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: no_map passed ✅\n");
}

Test(cub3d, wrong_extension_cubb)
{
	t_result	res;
	char *args[] = {"maps/invalid/invalid_extension.cubbb", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: wrong_extension_cubb passed ✅\n");
}

Test(invalid, no_args)
{
	t_result	res;
	char *args[] = {NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: no_args passed ✅\n");
}

Test(invalid, empty_arg)
{
	t_result	res;
	char *args[] = {"", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: empty_arg passed ✅\n");
}

Test(invalid, hidden_file_in_folder)
{
	t_result	res;
	char *args[] = {"maps/invalid/.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: hidden_file_in_folder passed ✅\n");
}

Test(invalid, hidden_file)
{
	t_result	res;
	char *args[] = {".cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: hidden_file passed ✅\n");
}

Test(invalid, empty_xpm_file)
{
	t_result	res;
	char *args[] = {"maps/invalid/empty_xpm_file.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: empty_xpm_file passed ✅\n");
}

Test(invalid, linked_hidden_file_xpm)
{
	t_result	res;
	char *args[] = {"maps/invalid/link_xpm_file.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: linked_hidden_file_xpm passed ✅\n");
}

Test(invalid, invalid_char_in_map)
{
	t_result	res;
	char *args[] = {"maps/invalid/invalid_char_in_map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: invalid_char_in_map passed ✅\n");
}

Test(invalid, wrong_extension_txt)
{
	t_result	res;
	char *args[] = {"maps/invalid/invalid_extension.txt", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: wrong_extension_txt passed ✅\n");
}

Test(invalid, misplaced_info)
{
	t_result	res;
	char *args[] = {"maps/invalid/misplaced_info.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: misplaced_info passed ✅\n");
}

Test(invalid, missing_texture)
{
	t_result	res;
	char *args[] = {"maps/invalid/missing_texture.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: missing_texture passed ✅\n");
}

Test(invalid, only_map)
{
	t_result	res;
	char *args[] = {"maps/invalid/only_map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: only_map passed ✅\n");
}

Test(invalid, player_out_of_map)
{
	t_result	res;
	char *args[] = {"maps/invalid/player_out_of_map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: player_out_of_map passed ✅\n");
}

Test(invalid, random_content)
{
	t_result	res;
	char *args[] = {"maps/invalid/random_content.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: random_content passed ✅\n");
}

Test(invalid, space_in_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/space_in_color.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: space_in_colour passed ✅\n");
}

Test(invalid, blank_line_in_map)
{
	t_result	res;
	char *args[] = {"maps/invalid/blank_line_in_map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: blank_line_in_map passed ✅\n");
}

Test(invalid, multiple_maps)
{
	t_result	res;
	char *args[] = {"maps/invalid/multiple_maps.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: multiple_maps passed ✅\n");
}

Test(invalid, random_word_arg)
{
	t_result	res;
	char *args[] = {"lalalala", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: random_word_arg passed ✅\n");
}

Test(invalid, multiple_map_args)
{
	t_result	res;
	char *args[] = {"maps/valid/map.cub", "maps/valid/map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: multiple_map_args passed ✅\n");
}

Test(invalid, multiple_map_args_in_one_arg)
{
	t_result	res;
	char *args[] = {"maps/valid/map.cub maps/valid/map.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: multiple_map_args_in_one_arg passed ✅\n");
}

Test(invalid, spaces_in_xpm_file)
{
	t_result	res;
	char *args[] = {"maps/invalid/spaces_in_xpm_file.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: spaces_in_xpm_file passed ✅\n");
}

Test(invalid, extra_commas_in_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/extra_commas_in_colour.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: extra_commas_in_colour passed ✅\n");
}

Test(invalid, out_of_range_rgb_value)
{
	t_result	res;
	char *args[] = {"maps/invalid/out_of_range_rgb_value.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: out_of_range_rgb_value passed ✅\n");
}

Test(invalid, empty_rgb_value)
{
	t_result	res;
	char *args[] = {"maps/invalid/empty_rgb_value.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: empty_rgb_value passed ✅\n");
}

Test(invalid, no_space_after_element_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/no_space_after_element_colour.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: no_space_after_element_colour passed ✅\n");
}

Test(invalid, no_space_after_element_texture)
{
	t_result	res;
	char *args[] = {"maps/invalid/no_space_after_element_texture.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: no_space_after_element_texture passed ✅\n");
}

Test(invalid, negative_rgb_value)
{
	t_result	res;
	char *args[] = {"maps/invalid/negative_rgb_value.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: negative_rgb_value passed ✅\n");
}

Test(invalid, overflow_rgb_value)
{
	t_result	res;
	char *args[] = {"maps/invalid/overflow_rgb_value.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: overflow_rgb_value passed ✅\n");
}

Test(invalid, no_player)
{
	t_result	res;
	char *args[] = {"maps/invalid/no_player.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: no_player passed ✅\n");
}

Test(invalid, multiple_players)
{
	t_result	res;
	char *args[] = {"maps/invalid/multiple_players.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: multiple_players passed ✅\n");
}

Test(invalid, map_unclosed_on_top)
{
	t_result	res;
	char *args[] = {"maps/invalid/map_unclosed_on_top.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: map_unclosed_on_top passed ✅\n");
}

Test(invalid, map_unclosed_on_bottom)
{
	t_result	res;
	char *args[] = {"maps/invalid/map_unclosed_on_bottom.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: map_unclosed_on_bottom passed ✅\n");
}

Test(invalid, unclosed_map_edge_case)
{
	t_result	res;
	char *args[] = {"maps/invalid/unclosed_map_edge_case.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: unclosed_map_edge_case passed ✅\n");
}

Test(invalid, map_unclosed_left)
{
	t_result	res;
	char *args[] = {"maps/invalid/map_unclosed_left.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: map_unclosed_left passed ✅\n");
}

Test(invalid, map_unclosed_right)
{
	t_result	res;
	char *args[] = {"maps/invalid/map_unclosed_right.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: map_unclosed_right passed ✅\n");
}

Test(invalid, missing_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/missing_colour.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: missing_colour passed ✅\n");
}

Test(invalid, more_rgb_values_in_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/more_rgb_values_in_colour.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: more_rgb_values_in_colour passed ✅\n");
}

Test(invalid, less_rgb_values_in_colour)
{
	t_result	res;
	char *args[] = {"maps/invalid/less_rgb_values_in_colour.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: less_rgb_values_in_colour passed ✅\n");
}

Test(invalid, non_numeric_colour_component)
{
	t_result	res;
	char *args[] = {"maps/invalid/non_numeric_colour_component.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: non_numeric_colour_component passed ✅\n");
}

Test(invalid, double_texture)
{
	t_result	res;
	char *args[] = {"maps/invalid/double_texture.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: double_texture passed ✅\n");
}

Test(invalid, unknown_texture_identifier)
{
	t_result	res;
	char *args[] = {"maps/invalid/unknown_texture_identifier.cub", NULL};
	res = run_cub3d(args);

	check_invalid(res);
	printf("Test: unknown_texture_identifier passed ✅\n");
}