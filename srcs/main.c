/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:24:27 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/13 12:00:05 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	if (ac == 2)
		init(FDF_W, FDF_H, FDF_T, av[1]);
	else
		die(NULL, "ERROR: Usage: ./fdf <map.fdf>");
	return (0);
}