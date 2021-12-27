/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:58:26 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:39:15 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	space(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

int		check_map(char **map_split)
{
	int y;
	int x;

	x = 0;
	while (map_split[x])
	{
		y = 0;
		while (map_split[x][y])
		{
			if (!(map_split[x][y] == '0' || map_split[x][y] == '1' ||
				map_split[x][y] == '2' || map_split[x][y] == 'N' ||
				map_split[x][y] == 'S' || map_split[x][y] == 'E' ||
				map_split[x][y] == 'W' || map_split[x][y] == ' '))
			{
				printf("Error : Map invalid\n");
				exit(EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		find_pos(char **map_split, int *posx, int *posy, t_map *map)
{
	int y;
	int x;

	x = 0;
	while (map_split[x])
	{
		y = 0;
		while (map_split[x][y])
		{
			if (ft_isspawn(map_split[x][y]))
			{
				*posx = x;
				*posy = y;
				map->orientation = map_split[x][y];
				map->personnage += 1;
			}
			y++;
		}
		x++;
	}
	map->posx = *posx;
	map->posy = *posy;
	return (0);
}

int		ft_sstrlen(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}

int		flood_fill(char **my_map, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x > (ft_sstrlen(my_map) - 1)
	|| y > ((int)ft_strlen(my_map[x]) - 1) || my_map[x][y] == ' '
	|| my_map[x][y] == '\0')
	{
		ft_2dstrdel(&map->origin_map);
		ft_2dstrdel(&map->map_split);
		printf("Error : Map invalid\n");
		exit(EXIT_FAILURE);
	}
	if (my_map[x][y] == '1' || my_map[x][y] == 'q')
		return (1);
	my_map[x][y] = 'q';
	return (flood_fill(my_map, x + 1, y, map)
	* flood_fill(my_map, x - 1, y, map)
	* flood_fill(my_map, x, y + 1, map)
	* flood_fill(my_map, x, y - 1, map));
}
