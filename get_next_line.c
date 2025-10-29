/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:01 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/29 09:32:28 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static
char	end_of_file(int fd, char buffer[BUFFER_SIZE], char **ptr, char **line)
{
	ssize_t	bytes_read;

	if (!**ptr)
	{
		*ptr = buffer;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			*line = ft_realloc(*line, 0, 0);
			buffer[0] = 0;
		}
		else
			buffer[bytes_read] = 0;
	}
	return (**ptr == 0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*ptr = buffer;
	const char	*start;
	char		*line;
	size_t		len;

	len = 0;
	line = 0;
	while (!end_of_file(fd, buffer, &ptr, &line))
	{
		start = ptr;
		ptr = ft_strchrnul(start, '\n');
		ptr += *ptr == '\n';
		line = ft_realloc(line, len, len + (ptr - start) + 1);
		if (!line)
			return (0);
		ft_strlcpy(line + len, start, (ptr - start) + 1);
		len += ptr - start;
		if (*(ptr - 1) == '\n')
			break ;
	}
	return (line);
}
