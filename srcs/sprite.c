/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:16:15 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 10:34:57 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	nb_sprites(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->origin_map[i])
	{
		j = 0;
		while (map->origin_map[i][j])
		{
			if (map->origin_map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	map->numsprite = count;
}

void	pos_sprites(t_map *map)
{
	int i;
	int j;
	int sprite_i;
	int nb_sprite;

	i = 0;
	sprite_i = 0;
	nb_sprite = map->numsprite;
	if (!(map->sprite = malloc(sizeof(t_sprite) * nb_sprite)))
		error_malloc(map);
	while (map->origin_map[i])
	{
		j = 0;
		while (map->origin_map[i][j])
		{
			if (map->origin_map[i][j] == '2')
			{
				map->sprite[sprite_i].sprite_x = i + 0.5;
				map->sprite[sprite_i].sprite_y = j + 0.5;
				sprite_i++;
			}
			j++;
		}
		i++;
	}
}

void	sortsprites(t_map *map)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < map->numsprite)
	{
		j = i + 1;
		while (j < map->numsprite)
		{
			if (map->sprite[i].spritedist < map->sprite[j].spritedist)
			{
				tmp = map->sprite[i];
				map->sprite[i] = map->sprite[j];
				map->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	info_sprite(t_map *map)
{
	int i;

	i = 0;
	nb_sprites(map);
	pos_sprites(map);
	while (i < map->numsprite)
	{
		map->sprite[i].spritedist = ((map->move->dpos_x -
		map->sprite[i].sprite_x) *
		(map->move->dpos_x - map->sprite[i].sprite_x) +
		(map->move->dpos_y - map->sprite[i].sprite_y) *
		(map->move->dpos_y - map->sprite[i].sprite_y));
		i++;
	}
	sortsprites(map);
}

void	sprite_camera(t_map *map, double *zbuffer)
{
	int y;

	map->sprite->textx = (int)(256 * (map->sprite->stripe -
	(-map->sprite->spritew / 2 + map->sprite->screenx)) *
	map->text.textw / map->sprite->spritew) / 256;
	if (map->sprite->transfy > 0 && map->sprite->stripe > 0 &&
	map->sprite->stripe < map->width &&
	map->sprite->transfy < zbuffer[map->sprite->stripe])
	{
		y = map->sprite->drawstarty;
		while (y < map->sprite->drawendy)
		{
			map->sprite->d = (y) * 256 - map->height * 128 +
			map->sprite->spriteh * 128;
			map->sprite->texty = ((map->sprite->d * map->text.texth) /
			map->sprite->spriteh) / 256;
			map->sprite->color = map->text_used.sp_text.addr[map->text_used.
			sp_text.texth * map->sprite->texty + map->sprite->textx];
			if ((map->sprite->color & 0x0067FF77) != 0)
				map->img->addr[y * map->width +
				map->sprite->stripe] = map->sprite->color;
			y++;
		}
	}
	map->sprite->stripe++;
}
