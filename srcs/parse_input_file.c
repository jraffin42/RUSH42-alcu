/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:15:57 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/11 22:16:24 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/alum.h"

int		is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i] < '0' || str[i] > '9')
			return (NO);
	return (YES);
}

int is_valid_range(char *str)
{
	int i;

	i = ft_atoi(str);
	if (i < 1 || i > 10000)
		return (ERROR);
	return (OK);
}


int parse_input_file(char **av)
{
	int fd;
	char *line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (ERROR);

	while (get_next_line(&line, fd) > 0)
	{
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		if (is_number(line) == NO || is_valid_range(line) == NO)
		{
			free(line);
			return (ERROR);
		}
		free(line);
		line = NULL;
	}

	while (get_next_line(&line, fd) > 0)
	{
		if (*line != '\0')
		{
			free(line);
			return (ERROR);
		}
		free(line);
		line = NULL;
	}

	free(line);
	line = NULL;
	return (OK);
}
