/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:16:48 by ccoto             #+#    #+#             */
/*   Updated: 2021/02/15 11:57:40 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		find_chr(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	error_str(char *str)
{
	if (str[0] == '\0')
	{
		printf("Error : Path invalid\n");
		exit(EXIT_FAILURE);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	x;
	size_t	j;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && find_chr(set, s1[i]) == 1)
		i++;
	x = ft_strlen(s1);
	while (x >= i && find_chr(set, s1[x - 1]) == 1)
		x--;
	error_str((char *)s1);
	if (!(s2 = malloc(sizeof(char) * ((x - i) + 1))))
		return (NULL);
	j = 0;
	while (i < x)
		s2[j++] = s1[i++];
	s2[j] = 0;
	return (s2);
}
