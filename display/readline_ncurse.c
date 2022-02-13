/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_ncurse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:37:17 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 18:52:35 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	read_single_int(t_curse *c, WINDOW *w)
{
	int	err;
	int	i;

	err = 0;
	while (err != -1)
	{
		display_message(w, -1, "Press enter to break");
		err = mvwscanw(w, w->_maxy / 2, w->_maxx / 2, "%d", &i);
		if (err == 0 && i == 0)
		{
			display_message(w, -2, "Invalid input, press any key to continue");
			display_refresh(c);
			getch();
			i = 0;
		}
		else if (i <= 0 || i > 3)
		{
			display_message(w, -2, "Invalid input, press any key to continue");
			display_refresh(c);
			getch();
			i = 0;
		}
		else
			break ;
		wclear(w);
		box(w, 0, 0);
		display_refresh(c);
	}
	return (i);
}
