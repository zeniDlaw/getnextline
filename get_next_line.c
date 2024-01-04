/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:46:52 by ichettri          #+#    #+#             */
/*   Updated: 2024/01/04 17:46:41 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>

t_fd *get_fd(t_fd **list, int fd)
{
    t_fd *tmp;

    if (*list == NULL) {
        *list = (t_fd *)malloc(sizeof(t_fd));
        (*list)->fd = fd;
        (*list)->buffer = (char *)malloc(BUFFER_SIZE + 1);
        (*list)->start = 0;
        (*list)->end = 0;
        (*list)->next = NULL;
        return *list;
    }

    tmp = *list;
    while (tmp) {
        if (tmp->fd == fd) {
            return tmp;
        }
        tmp = tmp->next;
    }

    tmp = (t_fd *)malloc(sizeof(t_fd));
    tmp->fd = fd;
    tmp->buffer = (char *)malloc(BUFFER_SIZE + 1);
    tmp->start = 0;
    tmp->end = 0;
    tmp->next = *list;
    *list = tmp;

    return tmp;
}

char *get_next_line(int fd) {
    static t_fd *list;
    t_fd *current_fd = get_fd(&list, fd);
    char *line = NULL;
    int line_length = 0;

    while (1) {
        if (current_fd->start >= current_fd->end) {
            current_fd->end = read(fd, current_fd->buffer, BUFFER_SIZE);
            current_fd->start = 0;
        }

        if (current_fd->end == 0) {
            return line;
        }

        line = (char *)realloc(line, line_length + 2);
        if (line == NULL) {
            return NULL;
        }

        line[line_length] = current_fd->buffer[current_fd->start];
        line[line_length + 1] = '\0';
        line_length++;
        current_fd->start++;

        if (current_fd->buffer[current_fd->start - 1] == '\n' || current_fd->end == 0) {
            break;
        }
    }

    return line;
}

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}

