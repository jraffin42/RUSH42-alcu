/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:13:10 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 18:32:31 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"


static void color_on(void)
{
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
}

static void init_base_window(t_curse *c)
{
	initscr(); // MANDATORY
	raw();
	/*noecho();*/
	cbreak();
	keypad( stdscr, TRUE );
	getmaxyx(stdscr, c->row, c->col);
	color_on();
	wrefresh(stdscr);
}

static void init_all_subwindows(t_curse *c)
{
	c->title = newwin(c->row * 11 / 100, c->col, 0, 0);
	c->main = newwin(c->row * 59 / 100, c->col * 1, c->row * 11 / 100, 0);
	c->inst = newwin(c->row * 15 / 100, c->col * 1, c->row *  70 / 100, 0);
	c->input = newwin(c->row * 15 / 100, c->col * 1, c->row * 85 / 100, 0);
	box(c->title, 0, 0);
	box(c->main, 0, 0);
	box(c->input, 0, 0);
	box(c->inst, 0, 0);
}

void display_refresh(t_curse *c)
{
	box(c->title, 0, 0);
	box(c->main, 0, 0);
	box(c->input, 0, 0);
	box(c->inst, 0, 0);
	wrefresh(c->title);
	wrefresh(c->main);
	wrefresh(c->input);
	wrefresh(c->inst);
}
void display_init(t_curse *c)
{
	init_base_window(c);
	init_all_subwindows(c);
	/*init_all_windows(c);*/
	display_refresh(c);
}

