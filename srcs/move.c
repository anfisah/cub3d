/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:54:29 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:49 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_north(t_map *map)
{
	if (map->origin_map[(int)(map->move->dpos_x + map->move->dir_x *
		MOVESPEED)][(int)(map->move->dpos_y)] == '0')
		map->move->dpos_x += map->move->dir_x * MOVESPEED;
	if (map->origin_map[(int)(map->move->dpos_x)][(int)(map->move->dpos_y +
		map->move->dir_y * MOVESPEED)] == '0')
		map->move->dpos_y += map->move->dir_y * MOVESPEED;
}

void	move_south(t_map *map)
{
	if (map->origin_map[(int)(map->move->dpos_x - map->move->dir_x *
		MOVESPEED)][(int)(map->move->dpos_y)] == '0')
		map->move->dpos_x -= map->move->dir_x * MOVESPEED;
	if (map->origin_map[(int)(map->move->dpos_x)]
		[(int)(map->move->dpos_y - map->move->dir_y * MOVESPEED)] == '0')
		map->move->dpos_y -= map->move->dir_y * MOVESPEED;
}

void	moveright(t_map *map)
{
	if (map->origin_map[(int)(map->move->dpos_x + map->move->dir_y *
		MOVESPEED)][(int)(map->move->dpos_y)] == '0')
		map->move->dpos_x += map->move->dir_y * MOVESPEED;
	if (map->origin_map[(int)(map->move->dpos_x)][(int)(map->move->dpos_y -
		map->move->dir_x * MOVESPEED)] == '0')
		map->move->dpos_y -= map->move->dir_x * MOVESPEED;
}

void	moveleft(t_map *map)
{
	if (map->origin_map[(int)(map->move->dpos_x - map->move->dir_y *
		MOVESPEED)][(int)(map->move->dpos_y)] == '0')
		map->move->dpos_x -= map->move->dir_y * MOVESPEED;
	if (map->origin_map[(int)(map->move->dpos_x)][(int)(map->move->dpos_y +
		map->move->dir_x * MOVESPEED)] == '0')
		map->move->dpos_y += map->move->dir_x * MOVESPEED;
}

void	move(t_map *map)
{
	if (map->key.k_north == 1 || map->key.k_up == 1)
		move_north(map);
	if (map->key.k_south == 1 || map->key.k_down == 1)
		move_south(map);
	if (map->key.k_turn_right == 1)
		turn_right(map);
	if (map->key.k_turn_left == 1)
		turn_left(map);
	if (map->key.k_move_right == 1)
		moveright(map);
	if (map->key.k_move_left == 1)
		moveleft(map);
	if (map->key.k_esc == 1)
		ft_close(53, map);
}
