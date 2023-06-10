/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/10 16:53:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **map, int height)
{
	int	i;

	i = -1;
	if (map)
	{
		while (++i < height)
			free(map[i]);
		free(map);
		map = NULL;
	}
}
