/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 05:00:42 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/26 08:14:57 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	start = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (start);
}
