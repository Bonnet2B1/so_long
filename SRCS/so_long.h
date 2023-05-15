/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:35:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/15 18:49:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int 	height;
	int		width;
	int		collectible;
	int		exit;
	int		player;
}			t_map;

//	temp.c
void print_map(t_map *map);

//	parser.c
int		parser(char *file, t_map *m);

//	map_init.c
void	map_init(t_map *m);
t_map	*temp_init(t_map *m);

//	ft_strlen.c
int	ft_strlen(const char *s);

//	freeall.c
void	freeall(t_map *map);

//	ft_strdup_no_nl.c
char	*ft_strdup_no_nl(const char *src);

//	ft_strjoin.c
char	*ft_strjoin(char *s1, char *s2);

//	ft_calloc.c
void	*ft_calloc(size_t size, size_t count);

//	ft_split.c
char	**ft_split(const char *s, char c);

#endif