/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/30 17:18:54 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delet_img(t_map *map)
{
	mlx_delete_image(map->mlx, map->player_img);
	mlx_delete_image(map->mlx, map->collectible_img);
	mlx_delete_image(map->mlx, map->wall_img);
	mlx_delete_image(map->mlx, map->floor_img);
	mlx_delete_image(map->mlx, map->zennemy_img);
	mlx_delete_image(map->mlx, map->portal_img1);
	mlx_delete_image(map->mlx, map->portal_img2);
	mlx_delete_image(map->mlx, map->portal_img3);
	mlx_delete_image(map->mlx, map->portal_img4);
	mlx_delete_image(map->mlx, map->portal_img5);
	mlx_delete_image(map->mlx, map->portal_img6);
	mlx_delete_image(map->mlx, map->portal_img7);
	mlx_delete_image(map->mlx, map->portal_img8);
	mlx_delete_image(map->mlx, map->movement_img);
}

void	freeall(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	if (map->height)
	{
		while (++i <= map->height)
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
	}
	if (map->map)
	{
		free(map->map);
		map->map = NULL;
	}
	if (map->tx_loaded)
		delet_img(map);
	free(map);
	map = NULL;
}
