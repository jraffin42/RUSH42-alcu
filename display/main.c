/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:58:36 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 04:49:58 by wszurkow         ###   ########.fr       */
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
#define STOP 1
#define ERROR -1
#define CONTINUE 0

// ########################### STRUCT

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;

// ########################### UTILS // TODO replace or delete

void alum_putstr(char *str, int fd)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

// ########################### GNL // TODO replace gnl

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
	while (lst->next && lst->next->value > 0) // TODO [REVIEW] ADDED NON 0 CHECK
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

static size_t largest_stack(t_list *lst)
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

static void	print_single_line(size_t n, size_t largest)
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

	if (lst == NULL)
		return;
	write(1, _CLEAR, 8);
	largest = largest_stack(lst);
	while (lst)
	{
		n = lst->value;
		print_single_line(n, largest);
		lst = lst->next;
	}
}
// ########################### PROMPT


int prompt(t_list *lst, int *player, int *error)
{
	int i;
	char max_alum;
	t_list *last;
	char *line;

	line = NULL;

	i = 0;
	last = ft_lstlast(lst);
	if (last->value <= 0)
		return (STOP);

	// DISPLAY CURRENT PLAYER
	if (*player == AI)
		alum_putstr("[AI] ", 1);
	else if (*player == HUMAN)
		alum_putstr("[HUMAN] ", 1);

	// PRINT RANGE OF ACTION 1 - N
	max_alum = '3';
	if (last->value < 3)
		max_alum = last->value + '0';
	alum_putstr("Take 1 - ", 1);
	write(1, &max_alum, 1);
	alum_putstr(" matches\n" , 1);

	// PRINT ERROR MESSAGE IF ERROR FLAG RAISED
	if (*error)
	{
		alum_putstr("[ERROR] Invalid input\n", 1);
		*error = 0;
	}

	// GET INPUT
	if (get_next_line(&line, 1) < 0) // TODO [REVIEW] GNL STOPS AT 0 or -1
	{
		free (line);
		return (STOP);
	}

	// PARSE INPUT
	while (line[i]) // TODO replace with strlen
		i++;
	if (i == 0 || i == 1)
		if (*line >= '1' && *line <= max_alum)
		{
			last->value -= *line - 48;
			if (*player == AI)
				*player = HUMAN;
			else if (*player == HUMAN)
				*player = AI;
			free (line);
			return (CONTINUE);
		}

	// ERROR FLAG RAISED IF INVALID INPUT
	*error = 1;
	free (line);
	return (CONTINUE);
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
