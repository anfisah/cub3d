/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:40:53 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:39:00 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	turn_right(t_map *map)
{
	map->move->old_dirx = map->move->dir_x;
	map->move->dir_x = map->move->dir_x * cos(-ROT) -
	map->move->dir_y * sin(-ROT);
	map->move->dir_y = map->move->old_dirx * sin(-ROT) +
	map->move->dir_y * cos(-ROT);
	map->move->old_planex = map->move->plane_x;
	map->move->plane_x = map->move->plane_x * cos(-ROT) -
	map->move->plane_y * sin(-ROT);
	map->move->plane_y = map->move->old_planex * sin(-ROT) +
	map->move->plane_y * cos(-ROT);
}

void	turn_left(t_map *map)
{
	map->move->old_dirx = map->move->dir_x;
	map->move->dir_x = map->move->dir_x * cos(ROT) -
	map->move->dir_y * sin(ROT);
	map->move->dir_y = map->move->old_dirx * sin(ROT) +
	map->move->dir_y * cos(ROT);
	map->move->old_planex = map->move->plane_x;
	map->move->plane_x = map->move->plane_x * cos(ROT) -
	map->move->plane_y * sin(ROT);
	map->move->plane_y = map->move->old_planex * sin(ROT) +
	map->move->plane_y * cos(ROT);
}
