/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:11:37 by jraffin           #+#    #+#             */
/*   Updated: 2020/11/27 09:32:56 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	n;

	n = ft_strlen(s);
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	str[n] = '\0';
	while (n)
	{
		n--;
		str[n] = (*f)(n, s[n]);
	}
	return (str);
}
