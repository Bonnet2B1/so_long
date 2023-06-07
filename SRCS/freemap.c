/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/07 20:21:20 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **map, int height)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (++i < height)
		free(map[i]);
	free(map);
}
