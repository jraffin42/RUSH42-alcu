/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:58:36 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 03:28:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <time.h>
#include <stdio.h>

#define _CLEAR			"\x1B[2J\x1B[H"
#define AI 0
#define HUMAN 1
#define NEWLINE 		write(1, "\n", 1)

// ########################### STRUCT

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;

// ########################### GNL

static char *gnl_realloc(char *line, int *i)
{
	int l = 0;
	char *str;

	if (!(str = malloc(*i * 2)))
		return (NULL);
	*i *= 2;
	while (line && line[l])
	{
		str[l] = line[l];
		l++;
	}
	while(l < *i)
	{
		str[l] = 0;
		l++;
	}
	free(line);
	return(str);
}

int get_next_line(char **line, int fd)
{
	int r = 1;
	int i = -1;
	int malloc_size = 50;

	if (fd < 0)
		return (-1);
	if (!line)
		return(-1);
	*line = NULL;
	if (!(*line = gnl_realloc(*line, &malloc_size)))
		return (-1);
	while ((r = read(fd, &(*line)[++i], 1)))
	{
		if ((*line)[i] == 10)
			break ;
		if (i == malloc_size - 2)
			if (!(*line = gnl_realloc(*line, &malloc_size)))
				return (-1);
	}
	(*line)[i] = 0;
	return (r);
}


// ########################### LISTS

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->value = value;
		new->next = NULL;
	}
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			ft_lstlast(*alst)->next = new;
		else
			*alst = new;
	}
}

// ########################### ALUM DISPLAY

void alum_putstr(char *str, int fd)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}



size_t largest_stack(t_list *lst)
{
	size_t largest_int;

	if (lst == NULL)
		return (0);
	largest_int = 0;
	while (lst)
	{
		if (lst->value >= largest_int)
			largest_int = lst->value;
		lst = lst->next;
	}
	return (largest_int);
}

void	print_single_line(size_t n, size_t largest)
{
	int i;

	i = largest - n;
	while (i-- > 0)
		write (1, " ", 1);
	while (n--)
	{
		write (1, "|", 1);
		if (n != 0)
			write (1, " ", 1);
	}
	NEWLINE;
}

void print_alums(t_list *lst)
{
	size_t n;
	size_t largest;

	/*write(1, _CLEAR, 8);*/
	largest = largest_stack(lst);
	while (lst)
	{
		n = lst->value;
		print_single_line(n, largest);
		lst = lst->next;
	}
}
// ########################### PROMPT

void player_display_and_switch(int *player)
{
	if (*player == AI)
	{
		alum_putstr("[AI] ", 1);
		*player = HUMAN;
	}
	else if (*player == HUMAN)
	{
		alum_putstr("[HUMAN] ", 1);
		*player = AI;
	}
}

void prompt(t_list *lst, int *player)
{
	int i;
	char max_alum;
	t_list *last;
	char *line;

	i = 0;
	last = ft_lstlast(lst);

	if (*player == AI)
		alum_putstr("[AI] ", 1);
	else if (*player == HUMAN)
		alum_putstr("[HUMAN] ", 1);

	max_alum = '3';
	if (last->value < 3)
		max_alum = last->value + '0';
	alum_putstr("Take 1 - ", 1);
	write(1, &max_alum, 1);
	alum_putstr(" matches\n" , 1);

	if (get_next_line(&line, 1) < 0)
		return ; // TODO complete
	while (line[i]) // TODO replace strlen
		i++;
	if (i == 1 || i == 0)
	{
		if (*line >= '1' && *line <= '3')
		{
			last->value -= *line - 48;
			if (*player == AI)
				*player = HUMAN;
			else if (*player == HUMAN)
				*player = AI;
		}
		else
			alum_putstr("TRY AGAIN\n", 1);
	}
	else
		alum_putstr("TRY AGAIN\n", 1);


	/*if (*player == AI)*/
	/**player = HUMAN;*/
	/*if (*player == HUMAN)*/
	/**player = AI;*/
}

// ########################### TESTS

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
	char *line;
	int player = AI;

	srand(time(0));
	lst = generate_list();

	print_alums(lst);
	NEWLINE;
	prompt(lst, &player);

	while (1)
	{
		print_alums(lst);
		NEWLINE;
		prompt(lst, &player);
	}

	return (0);
}
