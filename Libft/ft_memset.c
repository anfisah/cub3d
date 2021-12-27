/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:59:34 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/23 14:12:36 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*str;

	i = 0;
	chr = (unsigned char)c;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = chr;
		i++;
	}
	return (b);
}
