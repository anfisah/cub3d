/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:04:14 by ccoto             #+#    #+#             */
/*   Updated: 2021/02/15 11:57:06 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char		*words(char *s, char c, char **str)
{
	int		i;
	int		sizeword;
	char	*word;
	int		start;

	i = 0;
	sizeword = 0;
	start = i;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		sizeword++;
		i++;
	}
	if (!(word = malloc(sizeof(char) * (sizeword + 1))))
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(word, &s[start], sizeword);
	word[sizeword] = 0;
	return (word);
}

char			**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		indexmot;

	i = 0;
	indexmot = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char *) * (nb_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!(str[indexmot++] = words(&((char *)s)[i], c, str)))
				return (NULL);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	str[indexmot] = 0;
	return (str);
}
