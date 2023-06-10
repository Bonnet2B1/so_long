/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/10 15:38:50 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parser(char *file, t_map *m)
{
	if (!valid_file(file) || !create_map(file, m) || !closed_rectangle(m)
		|| !count_obj(m) || !valid_way(temp_init(m),
			copy_map(m, m->map), find_player_x(m), find_player_y(m)))
		return (0);
	return (1);
}
