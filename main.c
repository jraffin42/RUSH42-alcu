/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:30:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/11 22:31:01 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/alum.h"

#include <stdio.h> // TODO remove

int main(int ac, char **av)
{
	/*if (ac == 1)*/
	/*; // TODO no arguments, read from STDIN*/

	if (ac == 2)
		if (parse_input_file(av) == ERROR)
		{
			write(1, "ERROR\n", 6);
			return (ERROR);
		}


	return (0);
}
