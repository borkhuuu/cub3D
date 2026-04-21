#include "libft/libft.h"
#include <fcntl.h>

int	main()
{
	// int fd = open("test.txt", O_RDONLY);
	// for (char* line = get_next_line(fd); line; line = get_next_line(fd))
	// {
	// 	if (line[0] == '\n')
	// 		printf("line is empty ");
	// 	printf("line is:%s", line);
	// 	free(line);
	// }
	// char*	line2 = get_next_line(fd);
	// char**	arr = ft_split(line2, ' ');
	// printf("arr is %p\narr[0] is %s\narr[1] is %s\n", arr, arr[0], arr[1]);
	// if (arr[0][0] == '\n')
	// 	printf("yes");
//	char	*s = ft_strdup("hello\n");
//	ft_memset(ft_memchr(s, '\n', ft_strlen(s)), 0, 1);
//	printf("%s", s);
	write(1, NULL, 0);
	return 0;
}
