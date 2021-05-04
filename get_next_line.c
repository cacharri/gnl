/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:12:56 by ialvarez          #+#    #+#             */
/*   Updated: 2021/05/04 16:47:43 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static	char *reader[4096];
	char	rest[BUFFER_SIZE + 1];
	char	*tempor;
	char	*temporrr;
	int		i;

	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	/*i = read(fd, rest, BUFFER_SIZE);
	rest[i] = '\0';
	printf("yahacomooovengoyoo->>>>%s\n", rest);
	if (!reader[fd])
		reader[fd] = ft_strdup(rest);
	printf("yahorayeeees->>>>%s\n", reader[fd]);
	printf("yahacomooovengoyoo->>>>%s\n", rest);*/
	i = read(fd, rest, BUFFER_SIZE);
	while(i > 0)
	{
		rest[i] = '\0';
		if (!reader[fd])
			reader[fd] = ft_strdup(rest);
		if (reader[fd])
			reader[fd] = ft_strjoin(reader[fd], rest);
		//printf("yahorayeeees->>>>%s\n", reader[fd]);
		if ((tempor = ft_strchr(reader[fd], '\n')))
		{
			*tempor = '\0';
			*line = ft_strdup(reader[fd]);
		//	printf("nunyestuuu%s\n", *line); 
			temporrr = ft_strdup(++tempor);
		//	printf("presumisdeserbuenmozuu--->%s\n", temporrr);
			free(reader[fd]);
			reader[fd] = temporrr;
			free(temporrr);

			//printf("acomerlo---->%s\n", reader[fd]);
			//temporrr = ft_strchr(rest, '\n');
		//	reader[fd] = ft_strjoin(reader[fd], rest);
		//	printf("acomerlo---->%s\n", reader[fd]);
		//	printf("alo---->%s\n", *line);
		//	printf("reader: |%s|\n", reader[fd]);
			return (1);
		}
		i = read(fd, rest, BUFFER_SIZE);
	}
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
	}
	
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
