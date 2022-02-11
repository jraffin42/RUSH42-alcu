/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:45:02 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/09 10:02:36 by jraffin          ###   ########.fr       */
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

static const char	*next_segment(char const *s, char *set)
{
	if (!s)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	if (*s)
		return (s);
	return (NULL);
}

static size_t	count_segments(char const *s, char *set)
{
	const char	*next;
	size_t		count;

	count = 0;
	next = next_segment(s, set);
	while (next)
	{
		count++;
		s = next;
		while (*s && !ft_strchr(set, *s))
			s++;
		next = next_segment(s, set);
	}
	return (count);
}

char	**ft_splitset(char const *s, char *set)
{
	size_t		count;
	char		**strarray;
	const char	*next;

	count = count_segments(s, set);
	strarray = malloc(sizeof(char *) * (count + 1));
	if (!strarray)
		return (NULL);
	strarray[count] = NULL;
	count = 0;
	next = next_segment(s, set);
	while (next)
	{
		s = next;
		while (*s && !ft_strchr(set, *s))
			s++;
		strarray[count] = ft_strndup(next, s - next);
		if (!strarray[count])
			return (free_until(strarray, count), NULL);
		next = next_segment(s, set);
		count++;
	}
	return (strarray);
}
