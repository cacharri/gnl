/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:12:56 by ialvarez          #+#    #+#             */
/*   Updated: 2021/05/05 21:37:25 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static	char *reader[4096];
	char	rest[BUFFER_SIZE + 1];
	char	*tempor;
	char	*aux;
	int		i;

	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	i = read(fd, rest, BUFFER_SIZE);
	printf("%lu\n", sizeof(rest));
	/*if (ft_strchr(reader[fd], '\n') && i == 0)
	{
		i = 1;
	}*/

	while(i > 0)
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

		i = read(fd, rest, BUFFER_SIZE);
	}
	/*if (ft_strchr(reader[fd], '\n') && i == 0)
	{
		i = 1;
		return (1);
	}*/
	return (i);
}

int main()
{
    int fd;
    char *line;
    int n;
    line =(char *)malloc(1);
    fd = open ("texto.txt", O_RDWR);
    printf("fd imain>>>>>%d\n", fd);
    if (fd < 0)
        return(0);
    n =  get_next_line(fd, &line);
	while (n)
	{
		printf("LINEA ___MAIN->%s\n", line);
		free(line);
		n =  get_next_line(fd, &line);
		printf("N___MAIN->%d\n", n);

	}
	while(1)
			 
//	printf("LINEA ___MAIN11->%s\n", line);
//	free(line);
    //fd = open ("texto.txt", O_RDWR);
  //  n =  get_next_line(fd, &line);
   //printf("LINEA ___MAIN->%s\n", line);
//	printf("N___MAIN->%d\n", n);
    //n =  get_next_line(fd, &line);
   // free(line);
   // printf("LINEA ___MAIN->%s\n", line);
   // printf("N___MAIN->%d\n", n);
    //n =  get_next_line(fd, &line);
    //printf("LINEA ___MAIN->%s\n", line);
    //printf("N___MAIN->%d\n", n);
    //n =  get_next_line(fd, &line);
    //free(line);
    //printf("LINEA ___MAIN->%s\n", line);
    //printf("N___MAIN->%d\n", n);
    //n =  get_next_line(fd, &line);
    //printf("LINEA ___MAIN->%s\n", line);
    //printf("N___MAIN->%d\n", n);
    //free(line);
    //printf("%s\n", line);
}

