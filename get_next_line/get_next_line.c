/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:22:09 by mtitan            #+#    #+#             */
/*   Updated: 2021/10/23 18:22:10 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_read_left_str(int fd, char *left_str)
{
	char		*str;
	ssize_t		b;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	b = 1;
	while (!ft_strchr(left_str, '\n') && b != 0)
	{
		b = read(fd, str, BUFFER_SIZE);
		if (b == -1)
		{
			free(str);
			return (NULL);
		}
		str[b] = '\0';
		left_str = ft_strjoin(left_str, str);
	}
	free(str);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
