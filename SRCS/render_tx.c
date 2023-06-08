/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:24:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/09 00:11:19 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tx(t_map *m, char *path, int y, int x)
{
	mlx_image_t		*img;
	mlx_texture_t	*tx;

	tx = mlx_load_png(path);
	img = mlx_texture_to_image(m->mlx, tx);
	mlx_image_to_window(m->mlx, img, x * 64, y * 64);
	// mlx_image_to_window(m->mlx, mlx_texture_to_image(m->mlx, mlx_load_png(path)), x * 64, y * 64);
}