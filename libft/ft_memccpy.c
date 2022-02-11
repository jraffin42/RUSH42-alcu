/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 07:48:38 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/12 04:34:03 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0 && *((unsigned char *)src) != (unsigned char)c)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	if (n > 0)
	{
		*(char *)dest = *(char *)src;
		return ((char *)dest + 1);
	}
	return (0);
}
