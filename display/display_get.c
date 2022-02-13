/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:44:36 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 17:52:48 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int     display_get_max_width(void)
{
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	(void) row;
	return (col);
}

int     display_get_max_height(void)
{
	int row;
	int col;

	getmaxyx(stdscr, row, col);
	(void)col;
	return (row);
}

int     get_max_width(WINDOW *w)
{
	return (w->_maxx);
}

int     get_max_height(WINDOW *w)
{
	return (w->_maxy);
}
