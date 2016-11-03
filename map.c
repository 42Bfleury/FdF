/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:48:08 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 10:48:39 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_arraylen(char **array)
{
	size_t	len;

	len = 0;
	while (*(array++))
		len++;
	return (len);
}

static t_node	*atoi_line(char **s)
{
	int		i;
	t_node	*tab;
	char	**parse;

	i = 0;
	while (s[i])
		i++;
	tab = (t_node*)malloc(sizeof(t_node) * i);
	if (tab)
	{
		i = 0;
		while (s[i])
		{
			parse = ft_strsplit(s[i], ',');
			tab[i].height = ft_atoi(parse[0]);
			tab[i].color = -1;
			if (parse[1] && ft_strnstr(parse[1], "0x", 2))
				tab[i].color = ft_atoi_base(parse[1] + 2, BASE_16);
			else if (parse[1])
				tab[i].color = ft_atoi(parse[1]);
			i++;
		}
	}
	return (tab);
}

static t_node	**add_int_tab(t_node **tab, int *size, t_node *nt)
{
	t_node	**tmp;
	int		i;

	tmp = (t_node**)malloc(sizeof(t_node*) * (*size + 1));
	if (tmp)
	{
		i = 0;
		while (i < *size)
		{
			tmp[i] = tab[i];
			i++;
		}
		tmp[i] = nt;
		(*size)++;
		return (tmp);
	}
	return (tab);
}

static void		error_map(char *str)
{
	ft_putstr("Error: Map ");
	ft_putendl(str);
	exit(0);
}

void			load_map(t_event *e, char *path)
{
	int		fd;
	char	*str;
	char	**tb;
	int		s;

	fd = open(path, O_RDONLY);
	if (fd >= 0)
	{
		e->map.height = 0;
		while (get_next_line(fd, &str) == 1)
		{
			tb = ft_strsplit(str, ' ');
			s = ft_arraylen(tb);
			if (e->map.width == 0)
				e->map.width = s;
			if (s != e->map.width)
				error_map("isn't fomated correctly.");
			e->map.data = add_int_tab(e->map.data, &(e->map.height),
					atoi_line(tb));
		}
	}
	else
		error_map("isn't exist.");
}
