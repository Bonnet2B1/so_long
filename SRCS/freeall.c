/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/10 15:43:14 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_map *map)
{
	int	i;

	i = -1;
	if (map->height)
	{
		while (++i <= map->height)
			free(map->map[i]);
	}
	if (map->map)
		free(map->map);
	free(map);
}
