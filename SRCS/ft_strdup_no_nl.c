/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:28:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/06/10 15:42:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_no_nl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_no_nl(const char *src)
{
	int		i;
	char	*dup;

	if (!src)
		return (NULL);
	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen_no_nl(src) + 1));
	if (!dup)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
