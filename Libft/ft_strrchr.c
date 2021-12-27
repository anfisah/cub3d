/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:02:40 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/24 12:03:54 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = (char)c;
	i = ft_strlen(s);
	if (chr == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == chr)
			return ((char *)&s[i]);
	}
	return (NULL);
}
