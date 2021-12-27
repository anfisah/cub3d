/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:59:21 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/24 17:22:58 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (source < dest)
		while (len)
		{
			len--;
			dest[len] = source[len];
		}
	else
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	return (dst);
}
