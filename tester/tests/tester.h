#ifndef TESTER_H
# define TESTER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <strings.h>
# include <criterion/criterion.h>
# include <stdio.h>

# define VAL "valgrind"
# define FLAG1 "--leak-check=full"
# define FLAG2 "--quiet"
# define FLAG3 "--error-exitcode=42"
# define FLAG4 "--errors-for-leak-kinds=all"
# define FLAG5 "--trace-children=yes"
# define PROG "../cub3D"

typedef struct s_result
{
	char	stderr[1024];
	int		exit_code;
}	t_result;

int	exec_program(t_result *res, char *const argv[]);

#endif