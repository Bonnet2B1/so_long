/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:35:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 21:01:15 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int 	height;
	int		width;
	int		collectible;
	int		exit;
	int		player;
	int		p_x;
	int		p_y;
}			t_map;

//	temp.c

//	parser.c
int		parser(t_map *m);

//	map_init.c
void	map_init(t_map *m);
t_map	temp_init(t_map *m);	

//	ft_strlen.c
size_t	ft_strlen(const char *s);

//	freeall.c
void	freeall(t_map *map);

#endif