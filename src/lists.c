/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:45:48 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 13:46:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/display.h"

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
