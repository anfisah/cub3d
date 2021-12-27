/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:26:51 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 13:21:20 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		error_rgb(char *line, int i, t_map *map)
{
	while (line[i] != ',' && line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
			map->no_color++;
		i++;
	}
	return (0);
}

int		check_errors(t_map *map)
{
	if (map->error_path > 0)
	{
		printf("Error : Path invalid\n");
		exit(EXIT_FAILURE);
	}
	if (map->no_color > 0 || map->color.f_red < 0 || map->color.f_green < 0 ||
	map->color.f_blue < 0 || map->color.c_red < 0 || map->color.c_green < 0 ||
	map->color.c_blue < 0)
	{
		free_path(map);
		ft_2dstrdel(&map->map_split);
		ft_2dstrdel(&map->origin_map);
		printf("Error : Color\n");
		exit(EXIT_FAILURE);
	}
	if (map->error_xpm > 0)
	{
		free_path(map);
		ft_2dstrdel(&map->map_split);
		ft_2dstrdel(&map->origin_map);
		printf("Error : path format\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int		check_error2(t_map *map, t_id *id)
{
	if (id->r != 1 || id->c != 1 || id->s != 1 || id->f != 1 || id->no != 1 ||
		id->so != 1 || id->we != 1 || id->ea != 1)
	{
		free_path(map);
		ft_2dstrdel(&map->map_split);
		ft_2dstrdel(&map->origin_map);
		printf("Error : informations invalid\n");
		exit(EXIT_FAILURE);
	}
	if (map->personnage != 1)
	{
		free_path(map);
		ft_2dstrdel(&map->map_split);
		ft_2dstrdel(&map->origin_map);
		printf("Error : bad number of character\n");
		exit(EXIT_FAILURE);
	}
	if (map->error_resolution > 0 || map->width <= 0 || map->height <= 0)
	{
		ft_2dstrdel(&map->map_split);
		ft_2dstrdel(&map->origin_map);
		printf("Error : Resolution\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	error_malloc(t_map *map)
{
	ft_2dstrdel(&map->map_split);
	ft_2dstrdel(&map->origin_map);
	printf("Error : malloc\n");
	exit(EXIT_FAILURE);
}

void	free_path(t_map *map)
{
	free(map->no_text);
	free(map->so_text);
	free(map->we_text);
	free(map->ea_text);
	free(map->s_text);
}
