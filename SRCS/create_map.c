/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/07 18:11:59 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(char *file, t_map *m)
{
	char	*map_in_line;
	char 	*temp;
	int		fd;

	if (read(fd, "", 0) == -1)
		return (0);
	map_in_line = get_next_line(fd);
	temp = get_next_line(fd);
	while (map_in_line && temp)
	{
		m->height++;
		map_in_line = ft_strjoin(map_in_line, temp);
		temp = get_next_line(fd);
	}
	m->map = ft_split(map_in_line, '\n');
	return (print_map(m), free(map_in_line), 1);
}