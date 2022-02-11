/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 03:57:51 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/09 17:59:38 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>
#include "libft.h"

static size_t	ft_strlcpy_writtenlen(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((i + 1) < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (i);
}

void	ft_put_error(char *context, char *err_msg, char *more)
{
	static char	buf[PATH_MAX * 4 + 8];
	size_t		len;

	len = ft_strlcpy_writtenlen(buf, FT_PUT_ERROR_INTRO, PATH_MAX + 1);
	len += ft_strlcpy_writtenlen(buf + len, ": ", 3);
	if (context)
	{
		len += ft_strlcpy_writtenlen(buf + len, context, PATH_MAX + 1);
		len += ft_strlcpy_writtenlen(buf + len, ": ", 3);
	}
	if (!err_msg)
		err_msg = strerror(errno);
	len += ft_strlcpy_writtenlen(buf + len, err_msg, PATH_MAX + 1);
	if (more)
	{
		len += ft_strlcpy_writtenlen(buf + len, ": ", 3);
		len += ft_strlcpy_writtenlen(buf + len, more, PATH_MAX + 1);
	}
	len += ft_strlcpy_writtenlen(buf + len, "\n", 2);
	write(STDERR_FILENO, buf, len);
}
