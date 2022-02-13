/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:41:54 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 18:46:57 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../inc/board.h"
# include <ncurses.h>
# include <form.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_curse
{
	int row;
	int col;
	WINDOW *title;
	WINDOW *input;
	WINDOW *main;
	WINDOW *inst;
} t_curse;



// GETTERS
int		display_get_max_width(void); // from main window
int		display_get_max_height(void); // from main window

int		get_max_width(WINDOW *w); // from sub window
int		get_max_height(WINDOW *w); // from wub window

int	read_single_int(t_curse *c, WINDOW *w);

// INIT
void	display_init(t_curse *c);
void	display_refresh(t_curse *c);

// PUT
void    display_message(WINDOW *w, int offset, char *message); // which window, what offset (default = 0)
void    display_error(char *error);

void    display_board_curse(t_curse *c, t_board *board);

#endif
