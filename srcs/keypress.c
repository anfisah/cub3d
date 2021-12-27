/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:04:26 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:47 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exit_redcross(void)
{
	exit(EXIT_SUCCESS);
}

int	ft_close(int keycode, t_map *map)
{
	keycode = 0;
	mlx_destroy_window(map->img->mlx, map->img->win);
	exit(EXIT_SUCCESS);
}

int	ft_ispress(int keycode, t_map *map)
{
	if (keycode == TLEFT)
		map->key.k_turn_left = 1;
	else if (keycode == TRIGHT)
		map->key.k_turn_right = 1;
	else if (keycode == UP)
		map->key.k_up = 1;
	else if (keycode == DOWN)
		map->key.k_down = 1;
	else if (keycode == NORTH)
		map->key.k_north = 1;
	else if (keycode == SOUTH)
		map->key.k_south = 1;
	else if (keycode == MLEFT)
		map->key.k_move_left = 1;
	else if (keycode == MRIGHT)
		map->key.k_move_right = 1;
	else if (keycode == ESC)
		map->key.k_esc = 1;
	else if (keycode == HUD && map->key.hud == 0)
		map->key.hud = 1;
	else if (keycode == HUD && map->key.hud == 1)
		map->key.hud = 0;
	return (0);
}

int	ft_isrelease(int keycode, t_map *map)
{
	if (keycode == TLEFT)
		map->key.k_turn_left = 0;
	else if (keycode == TRIGHT)
		map->key.k_turn_right = 0;
	else if (keycode == UP)
		map->key.k_up = 0;
	else if (keycode == DOWN)
		map->key.k_down = 0;
	else if (keycode == NORTH)
		map->key.k_north = 0;
	else if (keycode == SOUTH)
		map->key.k_south = 0;
	else if (keycode == MLEFT)
		map->key.k_move_left = 0;
	else if (keycode == MRIGHT)
		map->key.k_move_right = 0;
	return (0);
}
