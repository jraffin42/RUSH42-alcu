/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:39:19 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 14:45:02 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/display.h"

static size_t	largest_stack(t_list *lst)
{
	int	largest_int;

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
	int	i;

	i = largest - n;
	while (i-- > 0)
		write (1, " ", 1);
	while (n--)
	{
		write (1, "|", 1);
		if (n != 0)
			write (1, " ", 1);
	}
	write(1, "\n", 1);
}

void	print_alums(t_list *lst)
{
	size_t	n;
	size_t	largest;

	if (lst == NULL)
		return ;
	write(1, _CLEAR, 8);
	largest = largest_stack(lst);
	while (lst)
	{
		n = lst->value;
		print_single_line(n, largest);
		lst = lst->next;
	}
}
