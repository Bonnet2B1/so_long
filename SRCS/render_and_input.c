/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:12:08 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/22 21:53:50 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_and_inputs(t_map *m)
{
	m->mlx = mlx_init(m->width * 64, (m->height + 1) * 64, "so_long", true);
	render_map(m, NULL);
	mlx_key_hook(m->mlx, &key, m);
	mlx_loop(m->mlx);
}
