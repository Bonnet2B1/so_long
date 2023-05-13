/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:23:29 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 20:57:06 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->p_x = 0;
	map->p_y = 0;
}

t_map	temp_init(t_map *m)
{
	int		i;
	t_map	*temp;

	i = -1;
	temp = malloc(sizeof(t_map));
	map_init(temp);
	while (m->map[++i])
		temp->map[i] = ft_strdup_no_nl(m->map[i]);
	temp->height = m->height;
	temp->width = m->width;
	temp->collectible = m->collectible;
	temp->exit = m->exit;
	temp->player = m->player;
	temp->p_x = m->p_x;
	temp->p_y = m->p_y;
	return (temp);
}
