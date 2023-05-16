/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:40:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/15 19:40:56 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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