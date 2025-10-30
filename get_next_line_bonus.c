/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:01 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/30 14:39:23 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];
	char		*ptr;
	char		*line;
	size_t		len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	len = 0;
	line = 0;
	while (!end_of_file(fd, buffer, &ptr, &line))
	{
		while (*ptr && *ptr++ != '\n')
			;
		line = ft_realloc(line, len, len + (ptr - buffer[fd]) + 1);
		if (!line)
			return (0);
		ft_strlcpy(line + len, buffer[fd], (ptr - buffer[fd]) + 1);
		len += ptr - buffer[fd];
		if (*(ptr - 1) == '\n')
			break ;
		ft_memmove(buffer[fd], ptr, ft_strlen(ptr) + 1);
	}
	ft_memmove(buffer[fd], ptr, ft_strlen(ptr) + 1);
	return (line);
}
