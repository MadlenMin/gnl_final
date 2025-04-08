/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminasya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:50:35 by mminasya          #+#    #+#             */
/*   Updated: 2025/04/08 21:24:49 by mminasya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char *fill_stash(int fd, char *stash);
char *update(char *stash);
char *get_the_line(char *stash);
char *get_next_line(int fd);
size_t ft_strlen(char *s);
char *ft_strdup(char *s1);
char *ft_strchr(char *s, int c);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strjoin(char *s1, char *s2);
#endif
