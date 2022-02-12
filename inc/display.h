/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:40:26 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/12 13:51:25 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <unistd.h>
#include <stdlib.h>

#define _CLEAR			"\x1B[2J\x1B[H"
#define AI 0
#define HUMAN 1
#define NEWLINE 		write(1, "\n", 1)
#define STOP 1
#define ERROR -1
#define CONTINUE 0

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;


int prompt(t_list *lst, int *player, int *error);

void	print_alums(t_list *lst);

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);


#endif
