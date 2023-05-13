/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 20:53:39 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] != 'r' || file[i - 1] != 'e'
		|| file[i - 2] != 'b' || file[i - 3] != '.')
		return (0);
	return (1);
}

int	create_map(char *file, t_map *m)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (write(fd, "", 0) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		m->map[++(m->height)] = ft_strdup_no_nl(line);
		free(line);
	}
	return (1);
}

int	rectangle(t_map *m)
{
	int y;
	y = 0;
	m->width = ft_strlen(m->map[0]);
	while (m->map[y])
	{
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (0);
		if (ft_strlen(m->map[y]) != m->width)
			return (0);
		y++;
	}
	return (1);
}

int	count_obj(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
				m->player++;
			if (m->map[y][x] == 'C')
				m->collectible++;
			if (m->map[y][x] == 'E')
				m->exit++;
			x++;
		}
		y++;
	}
	if (m->player != 1 || m->collectible < 1 || m->exit != 1)
		return (0);
	return (1);
}

void	find_player(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	m.map
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
			{
				m->p_x = x;
				m->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	valid_way(t_map *temp, int p_x, int p_y)
{
	//	if (1), return 0;
	if (temp->map[p_y][p_x] == '1')
		return 0;
	//	if (E) && collecible > 0; return 0;
	if (temp->map[p_y][p_x] == 'E' && temp->collectible > 0)
		return (0);
	//	if (E) && collecible == 0; return 1;
	if (temp->map[p_y][p_x] == 'E' && temp->collectible == 0)
		return (freeall(temp), 1);
	//	if (C), collectible--, transforme en 0;
	//	|_ valid_way(mm pos)
	if (temp->map[p_y][p_x] == 'C')
	{
		temp->map[p_y][p_x] = '1';
		if(!valid_way(temp, p_x, p_y))
			return (0);
	}
	//	if (0), transforme en 1;
	//	|_ if (!valid_way(x--, y) || x++,y || x, y-- || x, y++), return (0);
	if (temp->map[p_y][p_x] == '0')
	{
		temp->map[p_y][p_x] = '1';
		if(valid_way(temp, p_x--, p_y) || valid_way(temp, p_x++, p_y)
			|| valid_way(temp, p_x, p_y--) || valid_way(temp, p_x, p_y++))
			return (freeall(temp), 1);
		else
			return (freeall(temp), 0);
	}
}

int	parser(t_map *m)
{
	if (!valid_file(file) || !create_map(file, m) || !rectangle(m)
		|| !count_obj(m) || !valid_way(temp_init(m), m->p_x, m->p_y))
		return (0);
}
