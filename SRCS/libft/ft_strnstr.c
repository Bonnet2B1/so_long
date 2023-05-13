/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:23 by edelarbr          #+#    #+#             */
/*   Updated: 2022/12/05 20:31:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*haystack_notconst;

	if (!n && !haystack)
		return (NULL);
	haystack_notconst = (char *)haystack;
	i = 0;
	j = 0;
	if (!needle[j])
		return (haystack_notconst);
	while (haystack_notconst[i])
	{
		while (haystack_notconst[i + j] == needle[j]
			&& haystack_notconst[i + j] && i + j < n)
			j++;
		if (!needle[j])
			return (haystack_notconst + i);
		i++;
		j = 0;
	}
	return (0);
}
