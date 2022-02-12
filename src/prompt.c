/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:56 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 14:43:44 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/display.h"
#include "../inc/utils.h"

static void	display_current_player(int *player)
{
	if (*player == AI)
		ft_putstr_fd("[AI] ", 1);
	else if (*player == HUMAN)
		ft_putstr_fd("[HUMAN] ", 1);
}

static void	display_action_range(t_list *last, char *max_alum)
{
	*max_alum = '3';
	if (last->value < 3)
		*max_alum = last->value + '0';
	ft_putstr_fd("Take 1 - ", 1);
	write(1, max_alum, 1);
	ft_putstr_fd(" matches\n", 1);
}

static int	process_input(t_list *last, char *line, int *player, char max_alum)
{
	int	i;

	i = 0;
	i = ft_strlen(line);
	if (i == 2) // TODO why 2 ? GNL generates 2 chars instead of 1
	{
		if (*line >= '1' && *line <= max_alum)
		{
			last->value -= *line - 48;
			if (*player == AI)
				*player = HUMAN;
			else if (*player == HUMAN)
				*player = AI;
			free (line);
			return (STOP);
		}
	}
	return (CONTINUE);
}

int	prompt(t_list *lst, int *player, int *error)
{
	t_list	*last;
	char	max_alum;
	char	*line;

	line = NULL;
	last = ft_lstlast(lst);
	if (last->value <= 0)
		return (STOP);
	display_current_player(player);
	display_action_range(last, &max_alum);
	if (*error)
	{
		ft_putstr_fd("[ERROR] Invalid input\n", 1);
		*error = 0;
	}
	line = get_next_line(0);
	if (line)
		if (process_input (last, line, player, max_alum) == STOP)
			return (CONTINUE);
	*error = 1;
	free (line);
	if (line == NULL)
		return (STOP);
	return (CONTINUE);
}
