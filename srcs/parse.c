/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:45:08 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/14 02:46:52 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_nb_line(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		nb_char;
	int		nb_line;

	if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
		die(NULL, "ERROR: Failed to open file!(1)");
	nb_line = 0;
	while ((nb_char = get_next_line(fd, &line)))
	{
		if (nb_char < 0)
			die(NULL, "ERROR: Failed to read file! (1)");
		ft_strdel(&line);
		nb_line++;
	}
	close(fd);
	return (nb_line);
}

int			*convert_line(t_mlx *mlx, char *line)
{
	int			i;
	int			length;
	int			*result;
	char		**str_map;

	str_map = ft_strsplit(line, ' ');
	// length = ft_count_words(line, ' ');
	length = ft_count_words(line, ' ') - 1;
	if ((result = (int*)ft_memalloc(sizeof(int) * (length + 1))) == NULL)
		die(mlx, "ERROR: Failed to allocate line memory! (2)");
	result[0] = length;
	if (length > mlx->map.width)
		mlx->map.width = length;
	i = 0;
	while (i++ < length)
	{
		result[i] = ft_atoi(str_map[i - 1]);
		ft_strdel(&str_map[i - 1]);
	}
	free(str_map);
	return (result);
}

int			**parse_map(t_mlx *mlx)
{
	int			i;
	// int			fd;
	int			nb_char;
	char		*line;
	int			**result;

	size_t		j;
	FILE		*fd;

	if ((result = (int**)ft_memalloc(sizeof(int*) * mlx->map.height)) == NULL)
		die(NULL, "ERROR: Failed to allocate map memory! (1)");
	// if ((fd = open(mlx->map.file, O_RDONLY)) < 0)
	if ((fd = fopen(mlx->map.file, "r")) < 0)
		die(mlx, "ERROR: Failed to open file! (2)");
	i = 0;
	// while ((nb_char = get_next_line(fd, &line)))
	while ((nb_char = getline(&line, &j, fd)) > 0)
	{
		if (nb_char < 0)
			die(mlx, "ERROR: Failed to read file! (2)");
		result[i] = convert_line(mlx, line);
		i++;
		ft_strdel(&line);
	}
	// close(fd);
	fclose(fd);
	return (result);
}
