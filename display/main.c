
#include "display.h"
#include <curses.h>

void welcome(t_curse *c)
{
	char *msg;
	char *m;

	msg = "Welcome to 42 NIM";
	m = "Press ENTER to continue";
	box(stdscr, 0, 0);
	wrefresh(stdscr);
	attron(A_BOLD);
	mvprintw(c->row / 2, (c->col - strlen(msg))/2,"%s",msg);
	attroff(A_BOLD);
	mvprintw(c->row / 2 + 1, (c->col - strlen(m))/2,"%s",m);
	getch();
	wclear(stdscr);
	wrefresh(stdscr);
}

int main()
{

	t_curse *c;
	c = malloc (sizeof(t_curse));
	if (c == NULL)
		return (1);

	display_init(c);
	welcome(c); // PRESS ENTER TO CONTINUE

	wclear(c->title);
	wclear(c->main);
	wclear(c->inst);
	wclear(c->input);

	display_message(c->title, 0, "This is the title window (c->main)");
	display_message(c->main, 0, "This is the main window (c->main)");
	display_message(c->inst, 0, "This is the instruction window (c->inst)");
	display_message(c->input, 0, "This is the input window (c->input)");
	display_refresh(c); // Don't forget

	wclear(c->title);
	wclear(c->main);
	wclear(c->inst);
	wclear(c->input);

	getch();

	display_message(c->main, -1, "NOW");
	display_refresh(c);// Don't forget
	getch();

	display_message(c->main, 0, "CLEARING");
	display_refresh(c);// Don't forget
	getch();

	display_message(c->main, 2, "MAIN");
	display_refresh(c);// Don't forget
	getch();

	display_message(c->main, 3, "WINDOW");
	display_refresh(c);// Don't forget
	getch();

	wclear(c->title);
	wclear(c->main);
	wclear(c->inst);
	wclear(c->input);

	display_refresh(c);// Don't forget

	int i = read_single_int(c, c->input);

	printf("%s%d\n", "             i : ",              i);
	getch();

	display_message(c->main, 0, "Exiting...");// Don't forget
	display_refresh(c);// Don't forget

	sleep(3);


	return (0);
}
