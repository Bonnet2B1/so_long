/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:29:27 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 01:31:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_animation(t_map *m)
{
	
}

void	portal_anim(void *param)
{
	t_map	*m;

	m = param;
	if (m->collectible == 0)
		render_animation(m);
}