/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 07:22:30 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/12 20:44:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

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

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0 && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		n--;
	}
	if (n > 0)
		return ((void *)s);
	return (0);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		n = n % 10 + 48;
		write(1, &n, 1);
	}
}
