/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:50:38 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/13 10:21:53 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(char *path)
{
	char	*lastslash;

	if (path)
	{
		lastslash = ft_strrchr(path, '/');
		if (lastslash)
			return (lastslash + 1);
	}
	return (path);
}
