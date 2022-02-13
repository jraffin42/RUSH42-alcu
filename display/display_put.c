/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:01:19 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 18:13:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void    display_message(WINDOW *w, int row_offset, char *message)
{
	int	center_col;
	int	half_str_len;
	int	adjusted_col;

	center_col = w->_maxx / 2;
	half_str_len = strlen(message) / 2;
	adjusted_col = center_col - half_str_len;
	mvwprintw(w, w->_maxy / 2 + row_offset, adjusted_col,"%s", message); // print message at position
	box(w, 0, 0); // generate box (frame)
	refresh();
}

void    display_error(char *error)
{
	wclear(stdscr);
	display_message(stdscr, 0, error); // stdscr == main screen
}

