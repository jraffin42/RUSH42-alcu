#include "../inc/display.h"
#include "../inc/utils.h"

#include <time.h>

t_list *generate_list(void)
{
	t_list *lst;
	t_list *new;

	int a[10];

	for (int i = 0; i < 10; i++)
		a[i] = (rand() % 20) + 1;

	lst = ft_lstnew(a[0]); // TODO [CHECK THIS] necessary or lst_add_back segfaults

	for (int i = 1; i < 10; i++)
	{
		new = ft_lstnew(a[i]);
		ft_lstadd_back(&lst, new);
	}
	return lst;
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	t_list *lst;
	int    player;
	int    error;

	player = AI;
	error  = 0;

	srand(time(0));
	lst = generate_list();

	while (1)
	{
		print_alums(lst);
		NEWLINE;
		if (prompt(lst, &player, &error) == STOP)
			break;
	}
	t_list *tmp;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
	return (0);
}
