/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:12:08 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/09 01:15:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_and_inputs(t_map *m)
{
	m->mlx = mlx_init(m->width * 64, (m->height + 1) * 64, "so_long", true);
	render_map(m);
	// mlx_key_hook(s_map->mlx, &key, m);
	// mlx_loop_hook(s_map->mlx, &portal_anim, s_map);
	mlx_loop(m->mlx);
}