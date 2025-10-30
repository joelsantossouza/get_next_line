/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:55 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/30 13:07:18 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

# define MAX_FDS		1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	end_of_file(int fd, char buffer[MAX_FDS][BUFFER_SIZE + 1], char **line);
char	*get_next_line(int fd);

#endif
