/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:34:14 by ichettri          #+#    #+#             */
/*   Updated: 2024/01/04 17:05:34 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void    ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

static void	condition(char *st1, char *st2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		st1[i] = st2[i];
		i++;
	}
}

void	*ft_memmove(void *str1, const void *str2, int n)
{
	char	*st1;
	char	*st2;
	int		i;

	st1 = (char *)str1;
	st2 = (char *)str2;
	i = 0;
	if (st1 == NULL && st2 == NULL)
		return (NULL);
	if (st1 < st2)
	{
		condition(st1, st2, n);
	}
	else
	{
		while (n > 0)
		{
			st1[n - 1] = st2[n - 1];
			n--;
		}
	}
	return (str1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
