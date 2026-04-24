/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:02 by edelarbr         ###   ########.fr       */
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

int	valid_way(t_map *temp, int x, int y)
{
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
