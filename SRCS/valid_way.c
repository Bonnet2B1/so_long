/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/27 15:19:49 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				return (m->player_x = x);
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
				return (m->player_y = y);
		}
		x = -1;
	}
	return (0);
}

char	**copy_map(t_map *m, char **map)
{
	int		i;
	char	**new_map;

	i = -1;
	new_map = malloc(sizeof(char *) * (m->height + 1));
	if (!new_map)
		return (NULL);
	while (++i <= m->height)
		new_map[i] = ft_strdup_no_nl(map[i]);
	return (new_map);
}

// int	valid_way(t_map *temp, char **map, int x, int y)
// {
// 	print_map(map, temp->height);
// 	if (map[y][x] == 'P')
// 		map[y][x] = '0';
// 	if (map[y][x] == 'C')
// 	{
// 		temp->collectible--;
// 		map[y][x] = '0';
// 	}
// 	if (map[y][x] == 'E' && !temp->collectible)
// 		return (freemap(map, temp->height), 1);
// 	if (map[y][x] == '0' || (map[y][x] == '2' && !temp->collectible)
// 		|| map[y][x] == 'E')
// 	{
// 		if (temp->collectible && map[y][x] != 'E')
// 			map[y][x] = '2';
// 		else if (!temp->collectible && map[y][x] != 'E')
// 			map[y][x] = '1';
// 		if (valid_way(temp, copy_map(temp, map), (x - 1), y) || valid_way(temp,
// 				copy_map(temp, map), (x + 1), y) || valid_way(temp,
// 				copy_map(temp, map), x, (y - 1)) || valid_way(temp,
// 				copy_map(temp, map), x, (y + 1)))
// 			return (freemap(map, temp->height), 1);
// 		return (freemap(map, temp->height), 0);
// 	}
// 	return (freemap(map, temp->height), 0);
// }

int	valid_way(t_map *temp, int x, int y)
{
	if (!temp->map && temp->collectible)
		return (0);
	else if (!temp->map && !temp->collectible)
		return (1);
	if (temp->map[y][x] == '1' || temp->map[y][x] == 'Z')
		return (0);
	if (temp->map[y][x] == 'C' || temp->map[y][x] == 'E')
		temp->collectible--;
	temp->map[y][x] = '1';
	valid_way(temp, (x + 1), y);
	valid_way(temp, (x - 1), y);
	valid_way(temp, x, (y + 1));
	valid_way(temp, x, (y - 1));
	if (!temp->collectible)
		return (1);
	return (0);
}


// int	map_way(char **map, int px, int py)
// {
// 	static int	collectible;

// 	if (map[py][px] == '1'|| map[py][px] == 'F')
// 		return (0);
// 	if (map[py][px] == 'C' || map[py][px] == 'E')
// 		collectible++;
// 	map[py][px] = '1';
// 	map_way(map, px - 1, py);
// 	map_way(map, px + 1, py);
// 	map_way(map, px, py - 1);
// 	map_way(map, px, py + 1);
// 	return (collectible);
// }

// int	map_way_ok(char **map, int px, int py)
// {
// 	int	collect;

// 	collect = get_collect(map);
// 	return (map_way(map, px, py) == collect + 1);
// }