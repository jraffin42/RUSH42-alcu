/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 07:43:20 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/06 05:20:20 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (src == dest)
		return (dest);
	while (n)
	{
		n--;
		((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
