/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:51:23 by jraffin           #+#    #+#             */
/*   Updated: 2020/11/24 10:22:50 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*maplist;
	t_list	*ptrmap;

	if (!lst)
		return (NULL);
	maplist = ft_lstnew((*f)(lst->content));
	if (!maplist)
		return (NULL);
	ptrmap = maplist;
	lst = lst->next;
	while (lst)
	{
		ptrmap->next = ft_lstnew((*f)(lst->content));
		ptrmap = ptrmap->next;
		if (ptrmap)
			lst = lst->next;
		else
		{
			ft_lstclear(&maplist, del);
			lst = NULL;
		}
	}
	return (maplist);
}
