/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:45:08 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/06 11:11:51 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*convert_line(char *str)
{
	int		i;
	int		*int_tab;
	char	**map_line;

	i = 0;
	map_line = ft_strsplit(str, ' ');
	while (map_line[i])
		i++;
	int_tab = (int*)ft_memalloc(sizeof(int) * (i + 1));
	int_tab[0] = i;
	i = 0;
	while (map_line[i])
	{
		int_tab[i + 1] = ft_atoi(map_line[i]);
		i++;
	}
	return (int_tab);
}

static void		init_map(t_mlx mlx)
{
	int		i;
	int		fd;
	int		result;
	int		nb_line;
	char	*line;

	nb_line = 0;
	if ((fd = open(mlx.map.file, O_RDONLY)) < 0)
		exit(-1);
	while ((result = get_next_line(fd, &line)))
	{
		if (result < 0)
			exit(-1);
		i = ft_strlen(line);
		if (i > mlx.map.width)
			mlx.map.width = i;
		//ft_strdel(&line);
		nb_line++;
	}
	close(fd);
	mlx.map.height = nb_line;
	mlx.map.int_tab = (int**)ft_memalloc(sizeof(int*) * (nb_line + 1));
	ft_bzero(mlx.map.int_tab, (sizeof(int*) * (nb_line + 1)));
}

void 			convert_map(t_mlx mlx)
{
	int		i;
	int		fd;
	int 	result;
	char	*line;

	i = 0;
	init_map(mlx);
	if ((fd = open(mlx.map.file, O_RDONLY)) < 0)
		exit(-1);
	while ((result = get_next_line(fd, &line)))
	{
		if (result < 0)
			exit (-1);
		mlx.map.int_tab[i] = convert_line(line);
		//ft_strdel(&line);
		i++;
	}
}