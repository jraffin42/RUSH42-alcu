/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 07:22:30 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/12 14:45:43 by wsz              ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write (fd, str, ft_strlen(str));
}
