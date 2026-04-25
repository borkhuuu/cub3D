# include "tester.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_result	run_cub3d(char *args[])
{
	t_result	res;
	char		*argv[] = {"valgrind", "--quiet", "--leak-check=full", "--error-exitcode=42",
						"--errors-for-leak-kinds=all", "--trace-children=yes", PROG, NULL, NULL, NULL, NULL};
	int			i = 0;

	bzero(&res, sizeof(t_result));
	while (args[i])
	{
		argv[i + 7] = args[i];
		i++;
	}
	int fd = open("out", O_WRONLY);
	i = 0;
	while (argv[i])
	{
		dprintf(fd, "%s\n", argv[i]);
		i++;
	}
	close(fd);
	if (exec_program(&res, argv) == -1)
		cr_assert_fail("System error: couldn't execute test");
	return (res);
}
