/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:38:47 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 10:20:15 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dstrdel(char ***as)
{
	int		i;

	i = 0;
	if (as && *as)
	{
		while ((*as)[i])
			ft_strdel(&(*as)[i++]);
		free(*as);
		*as = NULL;
	}
}
