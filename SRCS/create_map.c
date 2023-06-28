/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 21:30:21 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(char *file, t_map *m)
{
	char	*map_in_line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	map_in_line = get_next_line(fd);
	temp = get_next_line(fd);
	while (map_in_line && temp)
	{
		m->height++;
		map_in_line = ft_strjoin(map_in_line, temp);
		temp = get_next_line(fd);
	}
	m->map = ft_split(map_in_line, '\n');
	return (close(fd), free(map_in_line), 1);
}
