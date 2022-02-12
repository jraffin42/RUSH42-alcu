/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:57 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/11 22:31:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ALUM_H__
# define __ALUM_H__

#include "colors.h"


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# define ERROR -1
# define OK     1
# define NO     0
# define YES    1

int get_next_line(char **line, int fd);
int			ft_atoi(const char *str);
int	ft_atoi_err(const char *str, int *nbr);
int parse_input_file(char **av);

#endif
