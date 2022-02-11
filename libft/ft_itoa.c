/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:40:56 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/10 14:44:11 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int value, char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_intlen(value);
	if (value > 0)
		value = -value;
	str[i--] = '\0';
	str[i--] = '0' - (value % 10);
	value /= 10;
	while (value)
	{
		str[i--] = '0' - (value % 10);
		value /= 10;
	}
	if (i >= 0)
		str[0] = '-';
	return (str);
}
