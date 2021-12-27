/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:15:11 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:54 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_orientation(t_map *map)
{
	if (map->orientation == 'N')
	{
		map->move->dir_x = -1;
		map->move->dir_y = 0;
	}
	if (map->orientation == 'S')
	{
		map->move->dir_x = 1;
		map->move->dir_y = 0;
	}
	if (map->orientation == 'W')
	{
		map->move->dir_x = 0;
		map->move->dir_y = -1;
	}
	if (map->orientation == 'E')
	{
		map->move->dir_x = 0;
		map->move->dir_y = 1;
	}
	map->move->plane_x = 0.66 * map->move->dir_y;
	map->move->plane_y = -0.66 * map->move->dir_x;
}

void	calc_next_step(t_map *map)
{
	if (map->move->ray_dirx < 0)
	{
		map->move->step_x = -1;
		map->move->side_distx = (map->move->dpos_x - map->move->map_x) *
		map->move->delta_distx;
	}
	else
	{
		map->move->step_x = 1;
		map->move->side_distx = (map->move->map_x + 1.0 - map->move->dpos_x) *
		map->move->delta_distx;
	}
	if (map->move->ray_diry < 0)
	{
		map->move->step_y = -1;
		map->move->side_disty = (map->move->dpos_y - map->move->map_y) *
		map->move->delta_disty;
	}
	else
	{
		map->move->step_y = 1;
		map->move->side_disty = (map->move->map_y + 1.0 - map->move->dpos_y) *
		map->move->delta_disty;
	}
}

void	calcul_dir(t_map *map, int *x)
{
	map->move->camera = 2 * *x / (double)map->width - 1;
	map->move->ray_dirx = map->move->dir_x + map->move->plane_x *
	map->move->camera;
	map->move->ray_diry = map->move->dir_y + map->move->plane_y *
	map->move->camera;
	map->move->map_x = (int)map->move->dpos_x;
	map->move->map_y = (int)map->move->dpos_y;
	map->move->delta_distx = fabs(1 / map->move->ray_dirx);
	map->move->delta_disty = fabs(1 / map->move->ray_diry);
	map->move->hit = 0;
}
