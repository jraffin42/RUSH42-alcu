/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:54:56 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/06 05:16:53 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				neg;
	unsigned long	abs;

	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	abs = 0;
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (abs >= 922337203685477580
			&& (abs > 922337203685477580 || *str > '7'))
			return (neg - 1);
		abs *= 10;
		abs += *str - '0';
		str++;
	}
	return ((1 - 2 * neg) * abs);
}
