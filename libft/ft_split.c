/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:45:02 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/09 10:10:27 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_until(char **strarray, size_t count)
{
	while (count)
		free(strarray[--count]);
	free(strarray);
}

static const char	*next_segment(char const *s, char c)
{
	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	if (*s)
		return (s);
	return (NULL);
}

static size_t	count_segments(char const *s, char c)
{
	const char	*next;
	size_t		count;

	count = 0;
	next = next_segment(s, c);
	while (next)
	{
		count++;
		s = next;
		while (*s && *s != c)
			s++;
		next = next_segment(s, c);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	char		**strarray;
	const char	*next;

	count = count_segments(s, c);
	strarray = malloc(sizeof(char *) * (count + 1));
	if (!strarray)
		return (NULL);
	strarray[count] = NULL;
	count = 0;
	next = next_segment(s, c);
	while (next)
	{
		s = next;
		while (*s && *s != c)
			s++;
		strarray[count] = ft_strndup(next, s - next);
		if (!strarray[count])
			return (free_until(strarray, count), NULL);
		next = next_segment(s, c);
		count++;
	}
	return (strarray);
}
