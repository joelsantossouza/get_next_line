/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:45:55 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/30 12:12:52 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	end_of_file(int fd, char buffer[BUFFER_SIZE], char **ptr, char **line);
char	*get_next_line(int fd);

#endif
