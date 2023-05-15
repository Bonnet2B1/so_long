/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/15 18:43:51 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file)
{
	int	i;
	if (!file)
		return (0);
	i = ft_strlen(file) - 1;
	if (file[i] != 'r' || file[i - 1] != 'e'
		|| file[i - 2] != 'b' || file[i - 3] != '.')
		return (0);
	return (1);
}

int	create_map(char *file, t_map *m)
{
	char	*map_in_line;
	char 	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (read(fd, "", 0) == -1)
		return (0);
	map_in_line = get_next_line(fd);
	temp = get_next_line(fd);
	while ( map_in_line && temp)
	{
		m->height++;
		map_in_line = ft_strjoin(map_in_line, temp);
		temp = get_next_line(fd);
	}
	m->map = ft_split(map_in_line, '\n');
	return (print_map(m), free(map_in_line), 1);
}

int	rectangle(t_map *m)
{
	int y;
	y = -1;
	m->width = ft_strlen(m->map[0]);
	while (m->map[++y])
	{
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (0);
		if (ft_strlen(m->map[y]) != m->width)
			return (0);
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

int	find_player_x(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (m->map[++y])
	{
		while (m->map[y][++x])
		{
			if (m->map[y][x] == 'P')
				return (x);
		}
		x = -1;
	}
	return (0);
}

int	find_player_y(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (m->map[++y])
	{
		while (m->map[y][++x])
		{
			if (m->map[y][x] == 'P')
				return (y);
		}
		x = -1;
	}
	return (0);
}

int	valid_way(t_map *temp, int x, int y)
{
	if (temp->map[y][x] == 'P')
		temp->map[y][x] = '0';
	if (temp->map[y][x] == 'C')
	{
		temp->collectible--;
		temp->map[y][x] = '0';
	}
	if (temp->map[y][x] == 'E' && temp->collectible == 0)
		return (freeall(temp), write(1, "Ok\n", 3), 1);
	if (temp->map[y][x] == '0')
	{
		temp->map[y][x] = '1';
		if(valid_way(temp, (x - 1), y) || valid_way(temp, (x + 1), y)
			|| valid_way(temp, x, (y - 1)) || valid_way(temp, x, (y + 1)))
			return (freeall(temp), 1);
		return(freeall(temp), 0);
	}
	return (0);
}

int	parser(char *file, t_map *m)
{
	if (!valid_file(file) || !create_map(file, m) || !rectangle(m)
		|| !count_obj(m) || !valid_way(temp_init(m), find_player_x(m), find_player_y(m)))
		return (0);
	return (1);
}		
