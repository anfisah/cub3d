/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:05:41 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:52 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_dda(t_map *map)
{
	while (map->move->hit == 0)
	{
		if (map->move->side_distx < map->move->side_disty)
		{
			map->move->side_distx += map->move->delta_distx;
			map->move->map_x += map->move->step_x;
			map->move->side = 0;
		}
		else
		{
			map->move->side_disty += map->move->delta_disty;
			map->move->map_y += map->move->step_y;
			map->move->side = 1;
		}
		if (map->origin_map[map->move->map_x][map->move->map_y] == '1')
			map->move->hit = 1;
	}
}

void	ft_drawcol(t_map *map)
{
	if (map->move->side == 0)
		map->move->perp_walldist = (map->move->map_x - map->move->dpos_x +
		(1 - map->move->step_x) / 2) / map->move->ray_dirx;
	else
		map->move->perp_walldist = (map->move->map_y - map->move->dpos_y +
		(1 - map->move->step_y) / 2) / map->move->ray_diry;
	map->move->line_height = (int)(map->height / map->move->perp_walldist);
	map->move->draw_start = -map->move->line_height / 2 + map->height / 2;
	if (map->move->draw_start < 0)
		map->move->draw_start = 0;
	map->move->draw_end = map->move->line_height / 2 + map->height / 2;
	if (map->move->draw_end >= map->height)
		map->move->draw_end = map->height - 1;
}

void	put_textures(t_map *map, int *y, int *x)
{
	if (map->move->ray_dirx < 0 && map->move->side == 0)
	{
		map->img->addr[*y * map->width + *x] = map->text_used.n_text.addr
		[map->text_used.n_text.texth * map->text.tex_y + map->text.tex_x];
	}
	if (map->move->ray_dirx > 0 && map->move->side == 0)
	{
		map->img->addr[*y * map->width + *x] = map->text_used.s_text.addr
		[map->text_used.s_text.texth * map->text.tex_y + map->text.tex_x];
	}
	if (map->move->ray_diry > 0 && map->move->side == 1)
	{
		map->img->addr[*y * map->width + *x] = map->text_used.e_text.addr
		[map->text_used.e_text.texth * map->text.tex_y + map->text.tex_x];
	}
	if (map->move->ray_diry < 0 && map->move->side == 1)
	{
		map->img->addr[*y * map->width + *x] = map->text_used.w_text.addr
		[map->text_used.w_text.texth * map->text.tex_y + map->text.tex_x];
	}
}

void	text_to_wall(t_map *map, int *y, int *x)
{
	if (map->move->side == 0)
		map->text.wall = map->move->dpos_y + map->move->perp_walldist *
		map->move->ray_diry;
	else
		map->text.wall = map->move->dpos_x + map->move->perp_walldist *
		map->move->ray_dirx;
	map->text.wall -= floor((map->text.wall));
	map->text.tex_x = (int)(map->text.wall * (double)map->text.textw);
	if (map->move->side == 0 && map->move->ray_dirx > 0)
		map->text.tex_x = map->text.textw - map->text.tex_x - 1;
	if (map->move->side == 1 && map->move->ray_diry < 0)
		map->text.tex_x = map->text.textw - map->text.tex_x - 1;
	map->text.step = 1.0 * map->text.texth / map->move->line_height;
	map->text.tex_pos = (map->move->draw_start - map->height / 2 +
	map->move->line_height / 2) * map->text.step;
	while (*y < map->move->draw_end)
	{
		map->text.tex_y = (int)map->text.tex_pos & (map->text.texth - 1);
		map->text.tex_pos += map->text.step;
		put_textures(map, y, x);
		(*y)++;
	}
}

void	ft_put_color_img(t_map *map, int *x)
{
	int y;

	y = 0;
	map->color.color_ceiling = map->color.c_red * pow(16, 4) +
	map->color.c_green * pow(16, 2) + map->color.c_blue;
	map->color.color_floor = map->color.f_red * pow(16, 4) +
	map->color.f_green * pow(16, 2) + map->color.f_blue;
	while (y < map->move->draw_start)
	{
		map->img->addr[y * map->width + *x] = map->color.color_ceiling;
		y++;
	}
	text_to_wall(map, &y, x);
	while (y < map->height)
	{
		map->img->addr[y * map->width + *x] = map->color.color_floor;
		y++;
	}
}
