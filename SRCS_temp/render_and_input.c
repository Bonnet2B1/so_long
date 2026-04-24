/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:12:08 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/30 18:22:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_and_inputs(t_map *m)
{
	m->portal_x = find_portal_x(m);
	m->portal_y = find_portal_y(m);
	m->mlx = mlx_init(m->width * 64, (m->height + 1) * 64, "so_long", true);
	render_map(m, NULL);
	mlx_key_hook(m->mlx, &key, m);
	mlx_loop_hook(m->mlx, &portal_anim, m);
	mlx_loop(m->mlx);
}
