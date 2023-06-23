/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:23:29 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/23 20:08:36 by edelarbr         ###   ########.fr       */
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
	map->movements = 0;
	map->tx_loaded = 0;

	map->exit_img = NULL;
}

t_map	*temp_init(t_map *m)
{
	int		i;
	t_map	*temp;

	i = -1;
	temp = malloc(sizeof(t_map));
	if (!temp)
		return (NULL);
	map_init(temp);
	temp->map = malloc(sizeof(char *) * (m->height + 1));
	if (!temp->map)
		return (NULL);
	while (++i <= m->height)
		temp->map[i] = ft_strdup_no_nl(m->map[i]);
	temp->height = m->height;
	temp->width = m->width;
	temp->collectible = m->collectible + 1;
	temp->exit = m->exit;
	temp->player = m->player;
	return (temp);
}
