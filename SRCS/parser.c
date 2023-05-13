/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:28:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/05/13 17:10:49 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if (file_name[i] != '.' || file_name[i + 1] != 'b'
		|| file_name[i + 2] != 'e' || file_name[i + 3] != 'r'
		|| file_name[i + 4] != '\0')
		return (0);
	return (1);
}

int	create_map(int fd, t_map *m)
{
	
}

int	count_obj(t_map *m)

int	valid_way(t_map *m)

int	parser(t_map *m)
{
	//	le fichier est en .ber
	//	read 0 octets pour verifier si le fichier est lisible
	//	verifier la map
	//	|_	la map est entourée par des murs ( 1 )
	//	|_	checker si il n'y a pas d'autres caracteres que 0, 1, C, P et E
	//	|_	compter les P, C et E
	//	|_	la map contient le minimum (P,C,E)
	//	|_	la map contient au max (1 P et 1 E)
	//	|_	la map est réctangulaire
}





