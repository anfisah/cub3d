/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:02:19 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/24 13:38:29 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	str = (char *)haystack;
	to_find = (char *)needle;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while ((str[i] == to_find[j]) && j < ft_strlen(to_find) && i < len)
		{
			if (j == ft_strlen(to_find) - 1)
				return (&str[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
