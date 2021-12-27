/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:34:11 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 10:33:22 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	addr_text(t_map *map)
{
	map->text_used.n_text.img = mlx_xpm_file_to_image(map->img->mlx,
	map->no_text, &map->text_used.n_text.textw, &map->text_used.n_text.texth);
	map->text_used.n_text.addr = (int *)mlx_get_data_addr(
	map->text_used.n_text.img, &map->text_used.n_text.bpp,
	&map->text_used.n_text.line_length, &map->text_used.n_text.endian);
	map->text_used.s_text.img = mlx_xpm_file_to_image(map->img->mlx,
	map->so_text, &map->text_used.s_text.textw, &map->text_used.s_text.texth);
	map->text_used.s_text.addr = (int *)mlx_get_data_addr(
	map->text_used.s_text.img, &map->text_used.s_text.bpp,
	&map->text_used.s_text.line_length, &map->text_used.s_text.endian);
	map->text_used.e_text.img = mlx_xpm_file_to_image(map->img->mlx,
	map->ea_text, &map->text_used.e_text.textw, &map->text_used.e_text.texth);
	map->text_used.e_text.addr = (int *)mlx_get_data_addr(
	map->text_used.e_text.img, &map->text_used.e_text.bpp,
	&map->text_used.e_text.line_length, &map->text_used.e_text.endian);
	map->text_used.w_text.img = mlx_xpm_file_to_image(map->img->mlx,
	map->we_text, &map->text_used.w_text.textw, &map->text_used.w_text.texth);
	map->text_used.w_text.addr = (int *)mlx_get_data_addr(
	map->text_used.w_text.img, &map->text_used.w_text.bpp,
	&map->text_used.w_text.line_length, &map->text_used.w_text.endian);
	addr_sprites(map);
}

void	addr_sprites(t_map *map)
{
	map->text_used.sp_text.img = mlx_xpm_file_to_image(map->img->mlx,
	map->s_text, &map->text_used.sp_text.textw, &map->text_used.sp_text.texth);
	map->text_used.sp_text.addr = (int *)mlx_get_data_addr(
	map->text_used.sp_text.img, &map->text_used.sp_text.bpp,
	&map->text_used.sp_text.line_length, &map->text_used.sp_text.endian);
	map->text_used.life_text.img = mlx_xpm_file_to_image(map->img->mlx,
	"Textures/heart.xpm", &map->text_used.life_text.textw,
	&map->text_used.life_text.texth);
	map->text_used.life_text.addr = (int *)mlx_get_data_addr(
	map->text_used.life_text.img, &map->text_used.life_text.bpp,
	&map->text_used.life_text.line_length, &map->text_used.life_text.endian);
	map->text_used.knife_text.img = mlx_xpm_file_to_image(map->img->mlx,
	"Textures/gun.xpm", &map->text_used.knife_text.textw,
	&map->text_used.knife_text.texth);
	map->text_used.knife_text.addr = (int *)mlx_get_data_addr(
	map->text_used.knife_text.img, &map->text_used.knife_text.bpp,
	&map->text_used.knife_text.line_length, &map->text_used.knife_text.endian);
}

void	calcul_sprite(t_map *map, int *i)
{
	map->sprite->spritex = map->sprite[*i].sprite_x - map->move->dpos_x;
	map->sprite->spritey = map->sprite[*i].sprite_y - map->move->dpos_y;
	map->sprite->invdet = 1.0 / (map->move->plane_x * map->move->dir_y -
	map->move->dir_x * map->move->plane_y);
	map->sprite->transfx = map->sprite->invdet * (map->move->dir_y *
	map->sprite->spritex - map->move->dir_x * map->sprite->spritey);
	map->sprite->transfy = map->sprite->invdet * (-map->move->plane_y *
	map->sprite->spritex + map->move->plane_x * map->sprite->spritey);
	map->sprite->screenx = (int)((map->width / 2) * (1 +
	map->sprite->transfx / map->sprite->transfy));
	map->sprite->spriteh = abs((int)(map->height / (map->sprite->transfy)));
	map->sprite->drawstarty = -map->sprite->spriteh / 2 + map->height / 2;
	if (map->sprite->drawstarty < 0)
		map->sprite->drawstarty = 0;
	map->sprite->drawendy = map->sprite->spriteh / 2 + map->height / 2;
	if (map->sprite->drawendy >= map->height)
		map->sprite->drawendy = map->height - 1;
	map->sprite->spritew = abs((int)(map->height / (map->sprite->transfy)));
	map->sprite->drawstartx = -map->sprite->spritew / 2 + map->sprite->screenx;
	if (map->sprite->drawstartx < 0)
		map->sprite->drawstartx = 0;
	map->sprite->drawendx = map->sprite->spritew / 2 + map->sprite->screenx;
	if (map->sprite->drawendx >= map->width)
		map->sprite->drawendx = map->width - 1;
	map->sprite->stripe = map->sprite->drawstartx;
}
