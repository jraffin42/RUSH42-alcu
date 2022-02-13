/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:14:17 by jraffin           #+#    #+#             */
/*   Updated: 2022/02/13 20:56:08 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "board.h"

void	init_display(void);
int		max_displayable_width(void);
int		board_max_displayable_height(void);
void	endgame(void);

void	display_board(void);

void	display_welcome(void);
void	display_ai_move(int move);
void	display_info(char *msg);
void	display_error(char *error);
void	display_winner(int player); // player == ( 0:AI | 1:player )

#endif
