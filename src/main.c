/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:30:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 17:21:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "board.h"
#include "utils.h"

#define CLEAR "\x1B[2J\x1B[H"
#define RESET "\e[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"

static int	final_value_to_aim(t_board *board)
{
	t_heap	*heap;
	int		final_value;

	heap = board->first;
	final_value = 1;
	while (heap != board->last)
	{
		heap = heap->next;
		final_value = (heap->nb_al % 4 != final_value);
	}
	return (final_value);
}

static int	get_ai_move(t_board *board, char **ai_msg)
{
	static char	msg[11] = "AI took 0\n";
	int			final_value;
	int			move;

	write(1, CLEAR, 8);
	final_value = final_value_to_aim(board);
	move = (board->last->nb_al - final_value) % 4;
	if (!move)
		move = 1;
	msg[8] = move + '0';
	*ai_msg = msg;
	return (move);
}

static int	get_player_move(t_board *board)
{
	char	*line;
	int		move;

	line = NULL;
	while (!line)
	{
		if (board->last->nb_al >= 3)
			write(1, "Please choose between 1 and 3 items :\n", 38);
		else if (board->last->nb_al == 2)
			write(1, "Please choose between 1 and 2 items :\n", 38);
		else
			write(1, "You have no choice but to take the 1 last item :\n", 49);
		line = get_next_line(0);
		if (!line || (*line != '1'
				&& (*line != '2' || board->last->nb_al < 2)
				&& (*line != '3' || board->last->nb_al < 3))
			|| (line[1] != '\n' && line[1] != '\0'))
		{
			(write(1, CLEAR, 8), display_board(board));
			(write (1, RED, 8), write (1, "Invalid choice\n", 15));
			line = (write (1, RESET, 5), free(line), NULL);
		}
	}
	move = (write(1, CLEAR, 8), *line - '0');
	return (free(line), move);
}

static void	next_move(int *player, t_board *board)
{
	t_heap		*to_free;
	int			move;
	char		*ai_msg;

	if (*player)
		move = get_player_move(board);
	else
		move = get_ai_move(board, &ai_msg);
	board->last->nb_al -= move;
	if (!board->last->nb_al)
	{
		to_free = board->last;
		board->last = board->last->previous;
		board->nb_of_heaps--;
		if (board->nb_of_heaps)
			board->last->next = NULL;
		else
			board->first = NULL;
		free(to_free);
	}
	if (board->nb_of_heaps == 0)
		return ;
	*player = !*player;
	(display_board(board), write(1, GREEN, 8), write(1, ai_msg, 10));
	write (1, RESET, 5);
}

int	main(int argc, char **argv)
{
	static t_board	board;
	static int		player;
	int				fd;

	fd = 0;
	write(1, "\x1B[2J\x1B[H", 8);
	if (argc < 1 || argc > 2)
		return (write(2, "ERROR\n", 6), 1);
	if (argv[1])
		fd = open(argv[1], O_RDONLY);
	if (fd == -1 || parse_board(fd, &board))
		return (1);
	if (board.nb_of_heaps)
	{
		display_board(&board);
		write (1, "\033[0;33mPRESS ENTER TO CONTINUE\n\e[0m", 36);
		free(get_next_line(0));
	}
	while (board.nb_of_heaps)
	{
		next_move(&player, &board);
		if (!board.nb_of_heaps)
		{
			if (player)
				write (1, "The AI won! Sorry...\n", 22);
			else
				write (1, "You are the winner! Congratulations!\n", 37);
		}
	}
	return (0);
}
