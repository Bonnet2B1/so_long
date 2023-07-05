/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/05 19:59:08 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'Z' && line[i] != '\n')
			return (0);
	}
	return (1);
}

int	create_map(char *file, t_map *m)
{
	char	*map_in_one_line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	map_in_one_line = get_next_line(fd);
	temp = get_next_line(fd);
	while (map_in_one_line && temp)
	{
		if (!verify_line(map_in_one_line))
			return (close(fd), free(map_in_one_line), 0);
		m->height++;
		map_in_one_line = ft_strjoin(map_in_one_line, temp);
		temp = get_next_line(fd);
	}
	m->map = ft_split(map_in_one_line, '\n');
	return (close(fd), free(map_in_one_line), 1);
}
