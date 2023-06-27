/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/27 22:50:48 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		mlx_delete_image(map->mlx, map->player_img);
		mlx_delete_image(map->mlx, map->collectible_img);
		mlx_delete_image(map->mlx, map->wall_img);
		mlx_delete_image(map->mlx, map->floor_img);
		mlx_delete_image(map->mlx, map->zennemy_img);
		if (map->exit_img)
			mlx_delete_image(map->mlx, map->exit_img);
	}
	free(map);
	map = NULL;
}
