/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:20:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 17:49:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int get_max_heap_size(t_heap *heap)
{
	int max;

	max = 0;
	while (heap)
	{
		if (heap->nb_al > max)
			max = heap->nb_al;
		heap = heap->next;
	}
	return (max);
}

static char *int_to_msg(t_heap *heap, int max_heap_size)
{
	int		i;
	int		j;
	char *line;

	j = 0;
	i = 0;
	line = malloc (sizeof (char *) * (max_heap_size * 2) + 1);
	while (i++ < heap->nb_al)
	{
		line[j] = ' ';
		line[j + 1] = '|';
		j += 2;
	}
	line[j] = '\0';
	return (line);
}

void    display_board_curse(t_curse *c, t_board *board)
{
	int current_line;
	char *msg;
	int max_heap_size;
	t_heap *heap;

	heap = board->first;
	max_heap_size = get_max_heap_size(board->first);
	msg = NULL;
	current_line = 0 - board->nb_of_heaps / 2;
	while (heap)
	{
		msg = int_to_msg(heap, max_heap_size);
		display_message(c->main, current_line, msg);
		heap = heap->next;
		current_line++;
	}
	wrefresh(c->main);
}
