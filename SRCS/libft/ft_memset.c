/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:16:40 by edelarbr          #+#    #+#             */
/*   Updated: 2022/10/31 18:16:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*char_str;

	i = 0;
	char_str = (unsigned char *)b;
	while (i < n)
		char_str[i++] = (unsigned char)c;
	b = (void *)char_str;
	return (b);
}
