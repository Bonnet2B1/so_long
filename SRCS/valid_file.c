/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:36:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/28 21:31:03 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file)
{
	int		i;
	char	test[1];
	int		fd;

	fd = open(file, O_RDONLY);
	if (read(fd, test, 1) <= -0)
		return (0);
	close(fd);
	if (!file)
		return (0);
	i = ft_strlen(file) - 1;
	if (file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b'
		|| file[i - 3] != '.')
		return (0);
	return (1);
}
