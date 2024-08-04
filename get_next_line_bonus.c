/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:52:39 by marvin            #+#    #+#             */
/*   Updated: 2024/08/04 23:52:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_polish_line(char *line)
{
	char	*this_remainder;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	this_remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*this_remainder == 0)
	{
		free(this_remainder);
		this_remainder = NULL;
	}
	line[i + 1] = '\0';
	return (this_remainder);
}

char	*fill_buff_line(int fd, char *remainder, char *buff)
{
	char	*tmp;
	int		byt_rd;

	byt_rd = 1;
	while (byt_rd != 0)
	{
		byt_rd = read(fd, buff, BUFFER_SIZE);
		if (byt_rd == -1)
		{
			free(remainder);
			return (NULL);
		}
		else if (byt_rd == 0)
			break ;
		buff[byt_rd] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[FD_MAX];
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder[fd]);
		free(buff);
		remainder[fd] = NULL;
		buff = NULL;
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = fill_buff_line(fd, remainder[fd], buff);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	remainder[fd] = ft_polish_line(line);
	return (line);
}
