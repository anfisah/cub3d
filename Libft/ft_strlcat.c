/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:01:22 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/23 17:08:16 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcsize;

	i = 0;
	j = 0;
	srcsize = ft_strlen(src);
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && j + i + 1 < dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j != dstsize)
		dst[j + i] = 0;
	return (srcsize + j);
}
