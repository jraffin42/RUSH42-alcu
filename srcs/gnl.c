/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:42:02 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/11 21:40:16 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static char *gnl_realloc(char *line, int *i)
{
    int l = 0;
    char *str;

    if (!(str = malloc(*i * 2)))
        return (NULL);
    *i *= 2;
    while (line && line[l])
    {
        str[l] = line[l];
        l++;
    }
    while(l < *i)
    {
        str[l] = 0;
        l++;
    }
    free(line);
    return(str);
}

int get_next_line(char **line, int fd)
{
    int r = 1;
    int i = -1;
    int malloc_size = 50;

	if (fd < 0)
		return (-1);
    if (!line)
        return(-1);
    *line = NULL;
    if (!(*line = gnl_realloc(*line, &malloc_size)))
        return (-1);
    while ((r = read(fd, &(*line)[++i], 1)))
    {
        if ((*line)[i] == 10)
            break ;
        if (i == malloc_size - 2)
            if (!(*line = gnl_realloc(*line, &malloc_size)))
                return (-1);
    }
    (*line)[i] = 0;
    return (r);
}
