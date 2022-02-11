/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:03:56 by bcano             #+#    #+#             */
/*   Updated: 2022/02/06 05:58:10 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	char	*str;

	len1 = 0;
	len2 = 0;
	len3 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	if (s3)
		len3 = ft_strlen(s3);
	str = malloc(sizeof(char) * (len1 + len2 + len3 + 1));
	if (!str)
		return (NULL);
	str[len1 + len2 + len3] = '\0';
	while (len3-- > 0)
		str[len1 + len2 + len3] = s3[len3];
	while (len2-- > 0)
		str[len1 + len2] = s2[len2];
	while (len1-- > 0)
		str[len1] = s1[len1];
	return (str);
}
