/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:24:27 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/15 13:20:07 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

static int	check_extension(char *file)
{
	int		i;

	if (ft_strchr(file, '.'))
	{
		if ((i = ft_strlen(file)) >= 4 && !ft_strcmp(file + i - 4,".fdf"))
		{
			if (i == 4)
				die(NULL, "ERROR: wrong file name! <map.fdf>");
			return (1);
		}
		die(NULL, "ERROR: wrong file extension! <.fdf>");
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 2 && check_extension(av[1]))
		init(FDF_W, FDF_H, FDF_T, av[1]);
	else
		die(NULL, "ERROR: Usage: ./fdf <map.fdf>");
	return (0);
}