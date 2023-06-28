/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:16:46 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 20:57:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tx(t_map *m)
{
	m->tx = mlx_load_png("SRCS/assets/P.png");
	m->player_img = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/1.png");
	m->wall_img = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/0.png");
	m->floor_img = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/C.png");
	m->collectible_img = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/Z.png");
	m->zennemy_img = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx_loaded = 1;
}

void	render_map_part_two(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1')
		mlx_image_to_window(m->mlx, m->wall_img, x * 64, y * 64);
	if (m->map[y][x] == '0' || (m->map[y][x] == 'E' && m->collectible))
		mlx_image_to_window(m->mlx, m->floor_img, x * 64, y * 64);
	if (m->map[y][x] == 'P' || m->map[y][x] == 'e')
		mlx_image_to_window(m->mlx, m->player_img, x * 64, y * 64);
	if (m->map[y][x] == 'C')
		mlx_image_to_window(m->mlx, m->collectible_img, x * 64, y * 64);
	if (m->map[y][x] == 'Z')
		mlx_image_to_window(m->mlx, m->zennemy_img, x * 64, y * 64);
}

void	render_map(t_map *m, char **old_map)
{
	int	y;
	int	x;

	if (!m->tx_loaded)
	{
		load_tx(m);
		load_tx_portal(m);
	}
	y = -1;
	while (++y <= m->height)
	{
		x = -1;
		while (++x < m->width)
		{
			if (!old_map || old_map[y][x] != m->map[y][x])
				render_map_part_two(m, x, y);
		}
	}
}
