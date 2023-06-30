/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/30 18:52:04 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parser(char *file, t_map *m)
{
	t_map	*temp;

	if (!valid_file(file) || !create_map(file, m) || !closed_rectangle(m)
		|| !count_obj(m))
		return (0);
	temp = temp_init(m);
	if (!valid_way(temp, find_player_x(m), find_player_y(m)))
		return (freeall(temp), write(1, "The game isn't winable\n", 23), 0);
	return (freeall(temp), 1);
}
