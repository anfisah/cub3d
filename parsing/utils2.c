/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:59:41 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 11:43:36 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_id	count_id(char *line, int *i, t_id id)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O')
		id.no++;
	if (line[*i] == 'S' && line[*i + 1] == 'O')
		id.so++;
	if (line[*i] == 'W' && line[*i + 1] == 'E')
		id.we++;
	if (line[*i] == 'E' && line[*i + 1] == 'A')
		id.ea++;
	if (line[*i] == 'S' && line[*i + 1] == ' ')
		id.s++;
	if (line[*i] == 'C' && line[*i + 1] == ' ')
		id.c++;
	if (line[*i] == 'F' && line[*i + 1] == ' ')
		id.f++;
	if (line[*i] == 'R' && line[*i + 1] == ' ')
		id.r++;
	return (id);
}

void	struct_fill(char *line, char *str, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
		map->no_text = ft_strdup(str);
	if (line[0] == 'S' && line[1] == 'O')
		map->so_text = ft_strdup(str);
	if (line[0] == 'W' && line[1] == 'E')
		map->we_text = ft_strdup(str);
	if (line[0] == 'E' && line[1] == 'A')
		map->ea_text = ft_strdup(str);
	if (line[0] == 'S' && line[1] == ' ')
		map->s_text = ft_strdup(str);
}

void	error_color(t_map *map, char *line, int *i)
{
	while (line[*i] != 0)
	{
		if (line[*i] != ' ')
			map->no_color++;
		(*i)++;
	}
}

int		put_color(char *line, t_id *id, t_map *map, int *i)
{
	*id = count_id(line, i, *id);
	if (line[*i] == 'F')
	{
		(*i)++;
		map->color.f_red = check_color(line, i, map);
		map->color.f_green = check_color(line, i, map);
		map->color.f_blue = check_color(line, i, map);
		error_color(map, line, i);
	}
	if (line[*i] == 'C')
	{
		(*i)++;
		map->color.c_red = check_color(line, i, map);
		map->color.c_green = check_color(line, i, map);
		map->color.c_blue = check_color(line, i, map);
		error_color(map, line, i);
	}
	return (0);
}

char	*res_cpy(char *line, int *i, char *str)
{
	int j;

	j = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		str[j] = line[*i];
		j++;
		(*i)++;
	}
	str[j] = 0;
	return (str);
}
