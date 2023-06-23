/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:16:46 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/23 20:10:57 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_tx(t_map *m)
{
	mlx_texture_t	*tx;

	tx = mlx_load_png("SRCS/assets/P.png");
	m->player_img = mlx_texture_to_image(m->mlx, tx);
	mlx_delete_texture(tx);
	tx = mlx_load_png("SRCS/assets/1.png");
	m->wall_img = mlx_texture_to_image(m->mlx, tx);
	mlx_delete_texture(tx);
	tx = mlx_load_png("SRCS/assets/0.png");
	m->floor_img = mlx_texture_to_image(m->mlx, tx);
	mlx_delete_texture(tx);
	tx = mlx_load_png("SRCS/assets/C.png");
	m->collectible_img = mlx_texture_to_image(m->mlx, tx);
	mlx_delete_texture(tx);
	tx = mlx_load_png("SRCS/assets/Z.png");
	m->zennemy_img = mlx_texture_to_image(m->mlx, tx);
	mlx_delete_texture(tx);
	m->tx_loaded = 1;
}

void	render_map_part_two(t_map *m, int x, int y)
{
	if (m->map[y][x] == '1')
		mlx_image_to_window(m->mlx, m->wall_img, x * 64, y * 64);
	if (m->map[y][x] == '0' || (m->map[y][x] == 'E' && m->collectible))
		mlx_image_to_window(m->mlx, m->floor_img, x * 64, y * 64);
	if (m->map[y][x] == 'P')
		mlx_image_to_window(m->mlx, m->player_img, x * 64, y * 64);
	if (m->map[y][x] == 'C')
		mlx_image_to_window(m->mlx, m->collectible_img, x * 64, y * 64);
	if (m->map[y][x] == 'Z')
		mlx_image_to_window(m->mlx, m->zennemy_img, x * 64, y * 64);
}

void	render_map(t_map *m, char **old_map)
{
	mlx_texture_t	*tx;
	int	y;
	int	x;

	if (!m->tx_loaded)
		load_tx(m);
	y = -1;
	while (++y <= m->height)
	{
		x = -1;
		while (++x < m->width)
		{
			if (m->map[y][x] == 'E' && !m->collectible && !m->exit_img)
			{
				tx = mlx_load_png("SRCS/assets/E.png");
				m->exit_img = mlx_texture_to_image(m->mlx, tx);
				mlx_delete_texture(tx);				
				mlx_image_to_window(m->mlx, m->exit_img, x * 64, y * 64);
			}
			if (!old_map || old_map[y][x] != m->map[y][x])
				render_map_part_two(m, x, y);
		}
	}
}
