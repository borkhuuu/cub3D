/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:59:33 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/02 17:11:11 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*store_buffer(char *store, char *buffer, int bytes_read)
{
	char	*new_store;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (store == NULL)
		return (ft_strdup(buffer));
	new_store = ft_calloc(sizeof(char), (ft_strlen(store) + bytes_read + 1));
	if (new_store == NULL)
		return (free(store), NULL);
	while (store[i] != '\0')
	{
		new_store[i] = store[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		new_store[i + j] = buffer[j];
		j++;
	}
	new_store[i + j] = '\0';
	if (store[ft_strlen(store)] != '\n')
		free(store);
	return (new_store);
}

static int	read_line(char **store, char *buffer, int fd)
{
	int	bytes_read;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), -1);
	*store = store_buffer(*store, buffer, bytes_read);
	free(buffer);
	while (newl_check(*store) == 0 && bytes_read != 0)
	{
		buffer = ft_calloc(sizeof(char), bytes_read + 1);
		if (buffer == NULL)
			return (-1);
		bytes_read = read(fd, buffer, bytes_read);
		if (bytes_read < 0)
			return (free(buffer), -1);
		if (bytes_read == 0)
			return (free(buffer), 2);
		buffer[bytes_read] = '\0';
		*store = store_buffer(*store, buffer, bytes_read);
		free(buffer);
	}
	return (0);
}

char	*get_next_line(int *fd)
{
	static char	*store;
	char		*new_line;
	char		*buffer;
	int			ret;

	buffer = NULL;
	if (*fd < 0 || BUFFER_SIZE <= 0)
		return (free(store), NULL);
	ret = read_line(&store, buffer, *fd);
	if (store == NULL || ret == -1)
		return (free(store), store = NULL, close(*fd), *fd = -1, NULL);
	new_line = fetch_line(store);
	if (new_line == NULL)
		return (NULL);
	else if (store[0] == '\0' && new_line[0] == '\0')
		return (free(store), free(new_line),
			store = NULL, close(*fd), *fd = -1, NULL);
	else
		store = fetch_rest(store);
	if (ret == 2)
	{
		(free(store), close(*fd));
		*fd = -1;
	}
	return (new_line);
}
