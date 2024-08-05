/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:57:33 by pzaw              #+#    #+#             */
/*   Updated: 2024/08/05 16:52:49 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_remainder(char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	return (NULL);
}

char	*ft_polish_line(char *line)
{
	char	*this_remainder;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	this_remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!this_remainder)
		return (NULL);
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
			return (0);
		else if (byt_rd == 0)
			break ;
		buff[byt_rd] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buff);
		if (tmp)
			free(tmp);
		tmp = NULL;
		if (!remainder)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder [FD_MAX];
	char		*line;
	char		*buff;
	char		*line_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free_remainder(&remainder[fd]));
	line = fill_buff_line(fd, remainder[fd], buff);
	free(buff);
	if (!line)
		return (free_remainder(&remainder[fd]));
	remainder[fd] = ft_polish_line(line);
	line_result = ft_strdup(line);
	free(line);
	if (!line_result)
		return (free_remainder(&remainder[fd]));
	return (line_result);
}
