/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:10:19 by edelarbr          #+#    #+#             */
/*   Updated: 2022/11/23 15:10:19 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	defsign(long *n, int *s_len, char **s)
{
	int	n_cpy;

	n_cpy = *n;
	while (n_cpy / 10)
	{
		n_cpy /= 10;
		(*s_len)++;
	}
	if (*n < 0)
		(*s_len)++;
	*s = ft_calloc(*s_len + 2, sizeof(char));
}

char	*ft_itoa(int n)
{
	int		s_len;
	char	*s;
	long	nb;

	nb = n;
	s_len = 0;
	defsign(&nb, &s_len, &s);
	if (!s)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		s[s_len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}
