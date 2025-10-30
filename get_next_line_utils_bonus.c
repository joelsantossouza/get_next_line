/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/30 13:06:58 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest || !src)
		return (0);
	pdest = (unsigned char *) dest;
	psrc = (const unsigned char *) src;
	if (dest <= src)
		while (n--)
			*pdest++ = *psrc++;
	else
		while (n--)
			pdest[n] = psrc[n];
	return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;
	int		min;

	new = 0;
	if (new_size)
	{
		new = malloc(new_size);
		min = old_size;
		if (new_size < old_size)
			min = new_size;
		ft_memmove(new, ptr, min);
	}
	free(ptr);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	psrc = (const unsigned char *) src;
	if (src)
	{
		if (dst && size)
		{
			pdst = (unsigned char *) dst;
			while (size-- > 1 && *psrc)
				*pdst++ = *psrc++;
			*pdst = 0;
		}
		while (*psrc)
			psrc++;
	}
	return ((const char *) psrc - src);
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	end_of_file(int fd, char buffer[MAX_FDS][BUFFER_SIZE + 1], char **line)
{
	ssize_t	bytes_read;

	if (!*buffer[fd])
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
		{
			*line = ft_realloc(*line, 0, 0);
			buffer[fd][0] = 0;
		}
		else
			buffer[fd][bytes_read] = 0;
	}
	return (*buffer[fd] == 0);
}
