/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:58:13 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/23 14:47:36 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
