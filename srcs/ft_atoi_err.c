/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:54:56 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/11 22:20:10 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_err(const char *str, int *nbr)
{
	int				neg;
	unsigned int	abs;

	if (!*str)
		return (1);
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	abs = 0;
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (abs >= 214748364 && (abs > 214748364 || *str > ('7' + neg)))
			return (1);
		abs *= 10;
		abs += *str - '0';
		str++;
	}
	if (*str)
		return (1);
	*nbr = abs;
	if (neg)
		*nbr = -abs;
	return (0);
}
