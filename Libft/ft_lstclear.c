/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 03:06:10 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/26 05:12:03 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *sup;

	if (!*lst)
		return ;
	while (*lst)
	{
		sup = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = sup;
	}
}
