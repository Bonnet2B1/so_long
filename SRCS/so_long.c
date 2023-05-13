/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:34 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 18:30:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	map_init(m);
	if (!parser(argv[2], m);)
		return (write(2, "Error\n", 6));
	return (1);
}
