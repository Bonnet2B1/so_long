/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/09 00:11:50 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*m;

	if (argc != 2)
		return (write(2, "Error\n", 6));
	m = malloc(sizeof(t_map));
	map_init(m);
	if (!parser(argv[1], m))
		return (write(2, "Error\n", 6));
	m->mlx = mlx_init(m->width * 64, (m->height + 1) * 64, "so_long", true);
	render_map(m);
	mlx_loop(m->mlx);
	return (1);
}
