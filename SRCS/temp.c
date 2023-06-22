/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:15:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/22 22:06:02 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	printf("map:\n");
	while (++i <= height)
		printf("%s\n", map[i]);
}
