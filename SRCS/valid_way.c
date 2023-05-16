/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/15 19:41:45 by edelarbr         ###   ########.fr       */
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
