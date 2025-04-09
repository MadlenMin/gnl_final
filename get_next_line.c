/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminasya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:17:01 by mminasya          #+#    #+#             */
/*   Updated: 2025/04/09 22:21:42 by mminasya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//BBOOOJJJEEEEEVUGVUVHJVJHB<KHBKB<HBKBKJ
char *fill_stash(int fd, char *stash)
{
	char *buffer;
	char *tmp;
	int bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return(NULL);
	bytes_read = 1;
	while(bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);

		if(bytes_read <= 0)
		break;
	buffer[bytes_read] = '\0';
	tmp = ft_strjoin(stash, buffer);
	if(!tmp)
		return(free(stash), free(buffer), NULL);
	free(stash);
	stash = tmp;
	}
	free(buffer);
	if(bytes_read < 0)
		return(free(stash),NULL);
	return(stash); 
}

char *update(char *stash)
{
	char *new_stash;
	size_t len;
	char *tmp;
	
	if(!stash)
		return(NULL);
	new_stash = ft_strchr(stash, '\n');
	if(new_stash != NULL)
	{
		len = ft_strlen(new_stash + 1);
		tmp = ft_substr(new_stash + 1, 0 , len);
		if(!tmp)
			return(NULL);
		free(stash);
		stash = tmp;
	}
	else
	free(stash);
	return(NULL);
}

char *get_the_line(char *stash)
{
	char *line;
	char *position;
	
	if(!stash)
		return(NULL);
	position = ft_strchr(stash, '\n');
	if(position)
		line = ft_substr(stash, 0, (position - stash) + 1);
	else 
		line = ft_substr(stash, 0, ft_strlen(stash));
	return(line);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	stash = fill_stash(fd, stash);
	if(!stash)
		return(NULL);
	line = get_the_line(stash);
	if(!line)
		return(NULL);
	stash = update(stash);
	return(line);
}
/*
int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));	
	printf("%s", get_next_line(fd));

		printf("%s", get_next_line(fd));
		
		printf("%s", get_next_line(fd));
		
		printf("%s", get_next_line(fd));
		
	close(fd);
	return 0;
}*/
