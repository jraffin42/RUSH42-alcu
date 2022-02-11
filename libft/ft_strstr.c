/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:16:50 by jraffin           #+#    #+#             */
/*   Updated: 2022/01/15 22:16:39 by bcano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	size_t	max;
	size_t	i;

	max = ft_strlen(haystack);
	len = ft_strlen(needle);
	if (max < len)
		return (NULL);
	max -= len;
	i = 0;
	while (i <= max)
	{
		if (!ft_strncmp(needle, haystack + i, len))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
