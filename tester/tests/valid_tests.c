#include "tester.h"

Test(valid, hidden_a_file)
{
	t_result	res;
	char *args[] = {"maps/valid/.a.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: hidden_a_file(.a.cub) passed ✅\n");
}

Test(valid, hidden_cub_file)
{
	t_result	res;
	char *args[] = {"maps/valid/.cub.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: hidden_cub_file(.cub.cub) passed ✅\n");
}

Test(valid, double_xpm_extension)
{
	t_result	res;
	char *args[] = {"maps/valid/double_xpm_extension.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: double_xpm_extension passed ✅\n");
}

Test(valid, leading_zero_in_colour)
{
	t_result	res;
	char *args[] = {"maps/valid/leading_zero_in_colour.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: leading_zero_in_colour passed ✅\n");
}

Test(valid, multiple_extenstions_cub)
{
	t_result	res;
	char *args[] = {"maps/valid/multiple_extensions.cub.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: multiple_extenstions.cub.cub passed ✅\n");
}

Test(valid, nl_between_info)
{
	t_result	res;
	char *args[] = {"maps/valid/nl_between_info.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: nl_between_info passed ✅\n");
}

Test(valid, subject_minimal_cub)
{
	t_result	res;
	char *args[] = {"maps/valid/subject_minimal.cub", NULL};
	res = run_cub3d(args);

	check_valid(res);
	printf("Test: subject_minimal.cub passed ✅\n");
}
