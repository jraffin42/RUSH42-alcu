/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:56 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 13:53:59 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/display.h"

int ft_strlen(char *str) // TODO Move this
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr_fd(char *str, int fd) // TODO Move this
{
	write (fd, str, ft_strlen(str));
}

int prompt(t_list *lst, int *player, int *error)
{
	int i;
	char max_alum;
	t_list *last;
	char *line;

	line = NULL;

	i = 0;
	last = ft_lstlast(lst);
	if (last->value <= 0)
		return (STOP);

	// DISPLAY CURRENT PLAYER
	if (*player == AI)
		ft_putstr_fd("[AI] ", 1);
	else if (*player == HUMAN)
		ft_putstr_fd("[HUMAN] ", 1);

	// PRINT RANGE OF ACTION 1 - N
	max_alum = '3';
	if (last->value < 3)
		max_alum = last->value + '0';
	ft_putstr_fd("Take 1 - ", 1);
	write(1, &max_alum, 1);
	ft_putstr_fd(" matches\n" , 1);

	// PRINT ERROR MESSAGE IF ERROR FLAG RAISED
	if (*error)
	{
		ft_putstr_fd("[ERROR] Invalid input\n", 1);
		*error = 0;
	}

	// GET INPUT
	if (get_next_line(&line, 1) < 0) // TODO [REVIEW] GNL STOPS AT 0 or -1
	{
		free (line);
		return (STOP);
	}

	// PARSE INPUT
	 i = ft_strlen(line);
	if (i == 0 || i == 1)
		if (*line >= '1' && *line <= max_alum)
		{
			last->value -= *line - 48;
			if (*player == AI)
				*player = HUMAN;
			else if (*player == HUMAN)
				*player = AI;
			free (line);
			return (CONTINUE);
		}

	// ERROR FLAG RAISED IF INVALID INPUT
	*error = 1;
	free (line);
	return (CONTINUE);
}

