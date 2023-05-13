/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:17:49 by edelarbr          #+#    #+#             */
/*   Updated: 2022/10/31 18:17:49 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	slen;

	slen = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[slen])
		slen++;
	if (start >= slen)
		len = 0;
	if (slen - start < len)
		len = slen - start;
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (len-- && s[start])
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}
