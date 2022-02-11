/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 07:15:19 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/06 05:30:36 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (s1)
	{
		while (*s1 && ft_strchr(set, (int)*s1))
			s1++;
		len = ft_strlen(s1);
		while (len > 0 && ft_strchr(set, (int)s1[len - 1]))
			len--;
	}
	else
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s1[len];
	return (str);
}
