#include "tester.h"

int	exec_program(t_result *res, char *const argv[])
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (close(fd[0]), close(fd[1]), -1);
	if (pid == 0)
	{
		dup2(fd[1], STDERR_FILENO);
		close(fd[0]);
		close(fd[1]);
		execvp(argv[0], argv);
		exit(255);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		res->exit_code = WEXITSTATUS(status);
		if (res->exit_code == 255)
			return (close(fd[0]), -1);
	}
	else
		return (close(fd[0]), -1);
	if (read(fd[0], res->stderr, sizeof(res->stderr)) == -1)
		return (close(fd[0]), close(fd[1]), -1);
	close(fd[0]);
	return (0);
}
