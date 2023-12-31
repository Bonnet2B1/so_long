/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/05 20:00:10 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*m;

	if (argc != 2)
		return (write(1, "Error\n", 6));
	m = malloc(sizeof(t_map));
	map_init(m);
	if (!parser(argv[1], m))
		return (write(2, "Error\n", 6));
	render_and_inputs(m);
	mlx_terminate(m->mlx);
	return (1);
}
