/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:20:27 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:39:02 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		id_path(char *line, int *i)
{
	if ((line[*i] == 'N' && line[*i + 1] == 'O') ||
		(line[*i] == 'S' && line[*i + 1] == 'O') ||
		(line[*i] == 'W' && line[*i + 1] == 'E') ||
		(line[*i] == 'E' && line[*i + 1] == 'A') ||
		(line[*i] == 'S' && line[*i + 1] == ' '))
		return (1);
	return (0);
}

int		all_id(t_id *id)
{
	if (id->r == 1 && id->c == 1 && id->s == 1 && id->f == 1 &&
		id->no == 1 && id->so == 1 && id->we == 1 && id->ea == 1)
		return (1);
	return (0);
}

char	*ft_strjoin_map(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	s3 = calloc(1, (ft_strlen(s1) + ft_strlen(s2) + 2));
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\n';
	s3[i + 1] = '\0';
	free((char *)s1);
	return (s3);
}

int		check_infos(char *line, int *i, t_id *id)
{
	if (id->r != 1 || id->c != 1 || id->s != 1 || id->f != 1 ||
		id->no != 1 || id->so != 1 || id->we != 1 || id->ea != 1)
	{
		if (line[*i] != 'C' && line[*i] != 'N' && line[*i] != 'S' &&
			line[*i] != 'W' && line[*i] != 'R' && line[*i] != 'F' &&
			line[*i] != 'E' && line[*i] != ' ')
		{
			printf("Error : informations invalid");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int		ft_isspawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}
