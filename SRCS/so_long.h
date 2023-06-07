/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:35:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/07 18:39:45 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collectible;
	int		exit;
	int		player;
}			t_map;

//	temp.c
void		print_map(t_map *map);
int			parser(char *file, t_map *m);
//	map_init.c
void		map_init(t_map *m);
t_map		*temp_init(t_map *m);
int			ft_strlen(const char *s);
void		freeall(t_map *map);
char		*ft_strdup_no_nl(const char *src);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t size, size_t count);
char		**ft_split(const char *s, char c);
int			valid_file(char *file);
int			create_map(char *file, t_map *m);
int			closed_rectangle(t_map *m);
int			count_obj(t_map *m);
//	valid_way.c
int			find_player_x(t_map *m);
int			find_player_y(t_map *m);
int			valid_way(t_map *temp, int x, int y);
#endif