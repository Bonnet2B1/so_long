/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:40:13 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:50 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closed_rectangle(t_map *m)
{
	int	y;

	y = -1;
	m->width = ft_strlen(m->map[0]);
	if (m->width > 40 || m->height > 21)
		return (0);
	while (m->map[++y])
	{
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (0);
		if (ft_strlen(m->map[y]) != m->width)
			return (0);
	}
	return (1);
}
