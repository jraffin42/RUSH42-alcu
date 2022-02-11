/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:22:33 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/06 05:30:01 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	strlen = 0;
	if (s)
	{
		while (*s && start)
		{
			s++;
			start--;
		}
		while (strlen < len && s[strlen])
			strlen++;
	}
	str = malloc(sizeof(char) * (strlen + 1));
	str[strlen] = '\0';
	while (strlen--)
		str[strlen] = s[strlen];
	return (str);
}
