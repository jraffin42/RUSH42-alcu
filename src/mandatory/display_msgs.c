/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:37:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 21:15:49 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "display.h"
#include "board.h"
#include "utils.h"

void	display_welcome(void)
{
	char	c;

	write(1, "\e[1;33m", 7);
	write(1, "PRESS ENTER TO CONTINUE...", 26);
	write(1, "\e[0m\n", 5);
	read(0, &c, 1);
}

void	display_ai_move(int move)
{
	static char	msg[11] = "AI took 0";

	msg[8] = move + '0';
	write(1, "\e[1;32m", 7);
	write(1, msg, 9);
	write(1, "\e[0m\n", 5);
}

void	display_info(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}

void	display_error(char *error)
{
	display_board();
	write(1, "\e[1;31m", 7);
	write(1, error, ft_strlen(error));
	write(1, "\e[0m\n", 5);
}

void	display_winner(int player)
{
	write(1, "\x1B[2J\x1B[H", 7);
	if (player)
	{
		write(1, "\e[1;32m", 7);
		write (1, "The AI won! Sorry...", 20);
	}
	else
	{
		write(1, "\e[1;94m", 7);
		write (1, "You are the winner! Congratulations!", 36);
	}
	write(1, "\e[0m\n", 5);
}
