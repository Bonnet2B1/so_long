/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:33:20 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 19:36:02 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_movement(t_map *m)
{
	char	*movement_str;

	mlx_delete_image(m->mlx, m->movement_img);
	movement_str = ft_itoa(m->movement);
	m->movement_img = mlx_put_string(m->mlx, movement_str, 0, 0);
	free(movement_str);
}
