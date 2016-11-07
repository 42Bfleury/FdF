/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:45:08 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 08:32:57 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_map(char *file, t_mlx *mlx)
{
	int		i;
	int		j;
	int		fd;
	int		nb_char;
	int		nb_line;
	int		length;
	int		*int_line;
	char	*line;
	char	**str_tab;

	mlx->map.file = file;
	if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
		exit(-1);
	nb_line = 0;
	line = ft_strnew(0);
	while ((nb_char = get_next_line(fd, &line)))
	{
		if (nb_char < 0)
			exit(-1);
		nb_line++;
	}
	close(fd);
	mlx->map.height = nb_line;
	mlx->map.width = 0;
	mlx->map.tab = (int**)ft_memalloc(sizeof(int*) * nb_line);
	if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
		exit(-1);
	i = 0;
	while ((nb_char = get_next_line(fd, &line)))
	{
		if (nb_char < 0)
			exit(-1);
		str_tab = ft_strsplit(line, ' ');
		length = ft_count_words(line, ' ');
		int_line = (int*)ft_memalloc(sizeof(int) * (length + 1));
		int_line[0] = length;
		if (length > mlx->map.width)
			mlx->map.width = length;
		j = 0;
		while (j < length)
		{
			int_line[j + 1] = ft_atoi(str_tab[j]);
			j++;
		}
		mlx->map.tab[i] = int_line;
		i++;
		ft_strdel(&line);
	}
	close(fd);
}
