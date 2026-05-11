# include "tester.h"

void	check_invalid(t_result res)
{
	if (res.exit_code == 0)
		cr_assert_fail("Exit code should not be 0 for errors");
	else if (res.exit_code == 42)
		cr_assert_fail("Valgrind detected errors");
	if (strncmp(res.stderr, "valgrind", 8) == 0)
		cr_assert_fail("Executable doesnt exist");
	else
		cr_assert(strncmp(res.stderr, "Error\n", 6) == 0,
         	    "stderr does not start with 'Error\\n'");
}
