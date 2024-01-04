/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:45:58 by ichettri          #+#    #+#             */
/*   Updated: 2024/01/04 18:21:01 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fd {
    int fd;
    char *buffer;
    int start;
    int end;
    struct s_fd *next;
} t_fd;


#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int     new_line(char *line);
size_t	ft_strlen(const char *str);
void    ft_strcpy(char *dest, char *src);
char    *get_next_line(int fd);
void append(char **line, char *buff);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *str1, const void *str2, int n);
void	ft_bzero(void *s, size_t n);

#endif