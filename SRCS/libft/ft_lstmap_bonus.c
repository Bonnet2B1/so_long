/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:17:59 by edelarbr          #+#    #+#             */
/*   Updated: 2022/12/05 19:16:56 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*firstlink;
	t_list	*tmp;

	firstlink = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = (*f)(lst->content);
		new = ft_lstnew(tmp);
		if (!new)
		{
			free(tmp);
			ft_lstclear(&firstlink, del);
			return (NULL);
		}
		ft_lstadd_back(&firstlink, new);
		lst = lst->next;
	}
	return (firstlink);
}
