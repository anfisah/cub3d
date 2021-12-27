/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:02:50 by ccoto             #+#    #+#             */
/*   Updated: 2021/01/20 10:51:24 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
