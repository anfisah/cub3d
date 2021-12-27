/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:54:33 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:45 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_map		init_struct_map(void)
{
	t_map map;

	map.width = 0;
	map.height = 0;
	map.no_text = NULL;
	map.so_text = NULL;
	map.we_text = NULL;
	map.ea_text = NULL;
	map.s_text = NULL;
	map.personnage = 0;
	map.fill_map = NULL;
	map.no_color = 0;
	map.error_path = 0;
	map.error_resolution = 0;
	map.map_split = NULL;
	map.error_xpm = 0;
	map.orientation = 0;
	map.posx = 0;
	map.posy = 0;
	map.numsprite = 0;
	map.save = 0;
	return (map);
}

t_move		init_struct_move(void)
{
	t_move move;

	move.dir_x = -1;
	move.dir_y = 0;
	move.plane_x = 0;
	move.plane_y = 0.66;
	move.camera = 0;
	move.ray_dirx = 0;
	move.ray_diry = 0;
	move.map_x = 0;
	move.map_y = 0;
	move.side_distx = 0;
	move.side_disty = 0;
	move.step_x = 0;
	move.step_y = 0;
	move.hit = 0;
	move.side = 0;
	move.delta_distx = 0;
	move.delta_disty = 0;
	move.perp_walldist = 0;
	move.dpos_x = 0;
	move.dpos_y = 0;
	move.draw_start = 0;
	move.draw_end = 0;
	return (move);
}

t_text		init_struct_text(void)
{
	t_text text;

	text.wall = 0;
	text.tex_x = 0;
	text.tex_y = 0;
	text.step = 0;
	text.tex_pos = 0;
	text.textw = 64;
	text.texth = 64;
	return (text);
}

t_key		init_struct_key(void)
{
	t_key key;

	key.k_turn_left = 0;
	key.k_turn_right = 0;
	key.k_up = 0;
	key.k_down = 0;
	key.k_move_left = 0;
	key.k_move_right = 0;
	key.k_north = 0;
	key.k_south = 0;
	key.k_esc = 0;
	key.hud = 0;
	return (key);
}

t_sprite	init_struct_sprite(void)
{
	t_sprite sprite;

	sprite.sprite_x = 0;
	sprite.sprite_y = 0;
	sprite.spritex = 0;
	sprite.spritey = 0;
	sprite.invdet = 0;
	sprite.transfx = 0;
	sprite.transfy = 0;
	sprite.screenx = 0;
	sprite.spriteh = 0;
	sprite.drawstarty = 0;
	sprite.drawendy = 0;
	sprite.spritew = 0;
	sprite.drawstartx = 0;
	sprite.drawendx = 0;
	sprite.textx = 0;
	sprite.d = 0;
	sprite.texty = 0;
	sprite.stripe = 0;
	sprite.color = 0;
	sprite.spritedist = 0;
	return (sprite);
}
