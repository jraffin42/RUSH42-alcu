/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:02:02 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/12 05:05:46 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			tmp = s;
		s++;
	}
	if (c)
		return ((char *)tmp);
	return ((char *)s);
}
