/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:57:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 21:05:41 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_map *map)
{
	int	i;

	i = -1;
	while (++i =< map->height)
		free(map->map[i]);
	free(map->map);
	free(map);
}
