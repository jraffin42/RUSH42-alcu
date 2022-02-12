/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:37:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 20:41:56 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

void	display_welcome(t_board *board)
{
	display_board(board);
	write (1, "\033[0;33mPRESS ENTER TO CONTINUE\n\e[0m", 36);
	free(get_next_line(0));
}

void	display_winner(int player)
{
	if (player)
		write (1, "The AI won! Sorry...\n", 22);
	else
		write (1, "You are the winner! Congratulations!\n", 37);
}
