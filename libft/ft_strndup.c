/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 08:36:15 by jraffin           #+#    #+#             */
/*   Updated: 2022/01/24 06:55:52 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (s[len] && len < n)
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst)
		ft_strlcpy(dst, s, len + 1);
	return (dst);
}
