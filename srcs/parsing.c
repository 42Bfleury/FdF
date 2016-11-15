/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:45:08 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/15 15:33:38 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	*convert_line(t_mlx *mlx, char *line)
{
	int			i;
	int			length;
	int			*result;
	char		**str_map;

	str_map = ft_strsplit(line, ' ');
	length = ft_count_words(line, ' ');
	if ((result = (int*)ft_memalloc(sizeof(int) * length)) == NULL)
		die(mlx, "ERROR: Failed to allocate line memory! (convert_line)");
	result[0] = length;
	if (!mlx->map.width && mlx->map.tab[0] == NULL)
		mlx->map.width = length;
	else if (length != mlx->map.width)
		die(mlx, "ERROR: Map not well formated!");
	i = 0;
	while (i++ < length)
	{
		result[i] = ft_atoi(str_map[i]);
		ft_strdel(&str_map[i]);
	}
	free(str_map);
	return (result);
}

int			**parse_map(t_mlx *mlx)
{
	int			i;
	int			fd;
	int			nb_char;
	char		*line;
	int			**result;

	if ((result = (int**)ft_memalloc(sizeof(int*) * mlx->map.height)) == NULL)
		die(NULL, "ERROR: Failed to allocate map memory! (parse_map)");
	if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
		die(mlx, "ERROR: Failed to open file! (parse_map)");
	i = 0;
	while ((nb_char = get_next_line(fd, &line)))
	{
		if (nb_char < 0)
			die(mlx, "ERROR: Failed to read file! (parse_map)");
		result[i] = convert_line(mlx, line);
		i++;
		ft_strdel(&line);
	}
	close(fd);
	return (result);
}

int			get_nb_line(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		nb_char;
	int		nb_line;

	if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
		die(NULL, "ERROR: Failed to open file!(get_nb_line)");
	nb_line = 0;
	while ((nb_char = get_next_line(fd, &line)))
	{
		if (nb_char < 0)
			die(NULL, "ERROR: Failed to read file! (get_nb_line)");
		ft_strdel(&line);
		nb_line++;
	}
	close(fd);
	return (nb_line);
}
