/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:37:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 21:11:58 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "board.h"
#include "utils.h"

#define ALCU_DISPLAY_MAX_WIDTH 80
#define ALCU_DISPLAY_MAX_BOARD_HEIGHT 20

void	init_display(void)
{
	NULL;
}

int	max_displayable_width(void)
{
	return (ALCU_DISPLAY_MAX_WIDTH);
}

int	board_max_displayable_height(void)
{
	return (ALCU_DISPLAY_MAX_BOARD_HEIGHT);
}

void	endgame(void)
{
	char	c;


	write(1, "\e[1;33m", 7);
	write(1, "PRESS ENTER TO EXIT...", 22);
	write(1, "\e[0m\n", 5);
	read(0, &c, 1);
}
