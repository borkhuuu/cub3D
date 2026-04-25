# include "tester.h"

void	check_valid(t_result res)
{
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	if (res.exit_code != 0)
		cr_assert_fail("Exit code should be 0 for success");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected leaks");
}
