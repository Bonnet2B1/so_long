/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:16:46 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/10 16:14:05 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *m)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= m->height)
	{
		x = -1;
		while (++x <= m->width)
		{
			if (m->map[y][x] == '1')
				render_tx(m, "SRCS/assets/1.png", y, x);
			if (m->map[y][x] == '0' || (m->map[y][x] == 'E' && m->collectible))
				render_tx(m, "SRCS/assets/0.png", y, x);
			if (m->map[y][x] == 'P')
				render_tx(m, "SRCS/assets/P.png", y, x);
			if (m->map[y][x] == 'C')
				render_tx(m, "SRCS/assets/C.png", y, x);
			if (m->map[y][x] == 'Z')
				render_tx(m, "SRCS/assets/Z.png", y, x);
			if (m->map[y][x] == 'E' && m->collectible == 0)
				render_tx(m, "SRCS/assets/E.png", y, x);
		}
	}
}
