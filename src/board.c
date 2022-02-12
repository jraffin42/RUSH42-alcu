/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 04:03:44 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/12 12:10:28 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "board.h"
#include "utils.h"

static t_heap	*new_heap(int nb_al, t_heap *previous)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	heap->nb_al = nb_al;
	heap->previous = previous;
	heap->next = NULL;
	return (heap);
}

static int	line_is_valid_number(const char *line, int *nbr)
{
	unsigned int	tmp;

	if (!*line || *line == '\n')
		return (0);
	tmp = 0;
	while (*line == '0')
		line++;
	while ('0' <= *line && *line <= '9')
	{
		tmp *= 10;
		tmp += *line - '0';
		if (tmp >= 10000)
			return (0);
		line++;
	}
	if (*line && *line != '\n')
		return (0);
	*nbr = tmp;
	return (1);
}

int	parse_board(int fd, t_board *board)
{
	char	*line;
	int		nbr;

	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line && line_is_valid_number(line, &nbr))
	{
		board->last = new_heap(nbr, board->last);
		if (!board->first)
			board->first = board->last;
		else
			board->last->previous->next = board->last;
		board->nb_of_heaps++;
		line = (free(line), get_next_line(fd));
	}
	if (!fd)
		line = (free(line), NULL);
	while (line && (*line == '\n' || !*line))
		line = (free(line), get_next_line(fd));
	if (line || errno)
		return (free(line), 1);
	return (0);
}

void	display_board(t_board *board)
{
	t_heap	*heap;
	int		max_heap_size;
	int		i;

	max_heap_size = 0;
	heap = board->first;
	while (heap)
	{
		if (heap->nb_al > max_heap_size)
			max_heap_size = heap->nb_al;
		heap = heap->next;
	}
	heap = board->first;
	while (heap)
	{
		i = max_heap_size - heap->nb_al;
		while (i--)
			write(1, " ", 1);
		i = 0;
		while (i++ < heap->nb_al)
			write(1, " |", 3);
		write (1, "\n", 1);
		heap = heap->next;
	}
}
