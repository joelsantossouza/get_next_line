/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/29 09:14:28 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest || !src)
		return (0);
	pdest = (unsigned char *) dest;
	psrc = (const unsigned char *) src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	new = 0;
	if (new_size)
	{
		new = malloc(new_size);
		ft_memcpy(new, ptr, ft_min(old_size, new_size));
	}
	free(ptr);
	return (new);
}

char	*ft_strchrnul(const char *s, int c)
{
	char	find;

	find = (char) c;
	if (s)
		while (*s)
			if (*s++ == find)
				return ((char *)(s - 1));
	return ((char *) s);
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
