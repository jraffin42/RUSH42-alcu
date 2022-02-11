/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:50:05 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/08 14:44:01 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_stpncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	i = 0;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
