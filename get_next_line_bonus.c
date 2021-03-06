/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:48:04 by ialvarez          #+#    #+#             */
/*   Updated: 2021/05/07 15:13:07 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	void	norris(char **reader, char *rest, int fd, int i)
{
	char	*aux;

	while (i > 0)
	{
		rest[i] = '\0';
		if (!reader[fd])
			reader[fd] = ft_strdup(rest);
		else
		{
			aux = ft_strjoin(reader[fd], rest);
			free(reader[fd]);
			reader[fd] = aux;
		}
		if (ft_strchr(rest, '\n'))
			break ;
		i = read(fd, rest, BUFFER_SIZE);
	}
}

static int	floki(int i, int fd, char **line, char **reader)
{
	char	*tempor;
	char	*aux;

	if (!reader[fd] && !i)
	{
		*line = ft_strdup("");
		return (0);
	}
	tempor = ft_strchr(reader[fd], '\n');
	if (tempor)
	{
		*tempor = '\0';
		*line = ft_strdup(reader[fd]);
		aux = ft_strdup(++tempor);
		free(reader[fd]);
		reader[fd] = aux;
		return (1);
	}
	else
	{
		*line = reader[fd];
		reader[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*reader[4096];
	char		rest[BUFFER_SIZE + 1];
	int			i;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || read(fd, rest, 0) < 0)
		return (-1);
	if (reader[fd] && ft_strchr(reader[fd], '\n'))
		return (floki(1, fd, line, reader));
	i = read(fd, rest, BUFFER_SIZE);
	norris(reader, rest, fd, i);
	return (floki(i, fd, line, reader));
}
