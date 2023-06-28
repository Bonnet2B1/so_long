/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:29:27 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 21:57:16 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_portal_x(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (m->map[++y])
	{
		while (m->map[y][++x])
		{
			if (m->map[y][x] == 'E')
				return (m->portal_x = x);
		}
		x = -1;
	}
	return (0);
}

int	find_portal_y(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (m->map[++y])
	{
		while (m->map[y][++x])
		{
			if (m->map[y][x] == 'E')
				return (m->portal_y = y);
		}
		x = -1;
	}
	return (0);
}

void	load_tx_portal(t_map *m)
{
	m->tx = mlx_load_png("SRCS/assets/portal/E1.png");
	m->portal_img1 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E2.png");
	m->portal_img2 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E3.png");
	m->portal_img3 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E4.png");
	m->portal_img4 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E5.png");
	m->portal_img5 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E6.png");
	m->portal_img6 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E7.png");
	m->portal_img7 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
	m->tx = mlx_load_png("SRCS/assets/portal/E8.png");
	m->portal_img8 = mlx_texture_to_image(m->mlx, m->tx);
	mlx_delete_texture(m->tx);
}

void	render_animation(t_map *m)
{
	if (m->portal_frame == 1)
		mlx_image_to_window(m->mlx, m->portal_img1, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 2)
		mlx_image_to_window(m->mlx, m->portal_img2, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 3)
		mlx_image_to_window(m->mlx, m->portal_img3, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 4)
		mlx_image_to_window(m->mlx, m->portal_img4, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 5)
		mlx_image_to_window(m->mlx, m->portal_img5, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 6)
		mlx_image_to_window(m->mlx, m->portal_img6, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 7)
		mlx_image_to_window(m->mlx, m->portal_img7, m->portal_x * 64,
			m->portal_y * 64);
	if (m->portal_frame == 8)
		mlx_image_to_window(m->mlx, m->portal_img8, m->portal_x * 64,
			m->portal_y * 64);
	m->portal_frame++;
}

void	portal_anim(void *param)
{
	t_map	*m;

	m = param;
	if (m->collectible == 0)
	{
		while (m->frame-- >= 0)
			return ;
		m->frame = 8;
		if (m->portal_frame > 8)
			m->portal_frame = 1;
		render_animation(m);
	}
}
