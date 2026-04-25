#ifndef TESTER_H
# define TESTER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <strings.h>
# include <criterion/criterion.h>
# include <stdio.h>

# define PROG "../cub3D"

typedef struct s_result
{
	char	stderr[1024];
	int		exit_code;
}	t_result;

int			exec_program(t_result *res, char *const argv[]);
t_result	run_cub3d(char *args[]);
void		check_invalid(t_result res);
void		check_valid(t_result res);

#endif