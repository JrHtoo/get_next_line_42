/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:54:59 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/08 13:46:02 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_modify(char *buffer, char *new)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, new);
	free(buffer);
	free(new);
	return (tmp);
}

static char	*ft_get_line(char *line_buffer)
{
	int		i;
	int		len;
	char	*line;

	if (line_buffer == NULL)
		return (NULL);
	len = ft_strlen(line_buffer);
	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	while (i < len)
	{
		i++;
		line_buffer[i] = '\0';
	}
	line = ft_strdup(line_buffer);
	return (line);
}

static char	*ft_get_leftc(char *line_buffer)
{
	int		i;
	int		len;
	char	*left_c;

	if (line_buffer == NULL)
		return (NULL);
	len = ft_strlen(line_buffer);
	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	left_c = ft_substr(line_buffer, i + 1, len - i);
	return (left_c);
}

static char	*ft_fill_line_buffer(int fd, char *buffer)
{
	char	*new;
	int		byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		byte_read = read(fd, new, BUFFER_SIZE);
		if (byte_read == 0)
		{
			free(new);
			return (buffer);
		}
		if (byte_read == -1)
		{
			free(new);
			return (NULL);
		}
		new[byte_read] = '\0';
		buffer = ft_modify(buffer, new);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[LIMIT];
	char		*left_c;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_fill_line_buffer(fd, buffer[fd]);
	left_c = ft_get_leftc(buffer[fd]);
	line = ft_get_line(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = ft_strdup(left_c);
	free(left_c);
	return (line);
}
