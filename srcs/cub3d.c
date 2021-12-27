/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:31:54 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/09 10:30:18 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	put_sprite(t_map *map, double *zbuffer)
{
	int i;

	i = 0;
	info_sprite(map);
	while (i < map->numsprite)
	{
		calcul_sprite(map, &i);
		while (map->sprite->stripe < map->sprite->drawendx)
			sprite_camera(map, zbuffer);
		i++;
	}
	if (map->save > 0)
		bmp(map);
	mlx_put_image_to_window(map->img->mlx, map->img->win,
	map->img->img, 0, 0);
	free(map->sprite);
	if (map->key.hud == 1)
	{
		mlx_put_image_to_window(map->img->mlx, map->img->win,
		map->text_used.life_text.img, 10, 10);
		mlx_put_image_to_window(map->img->mlx, map->img->win,
		map->text_used.knife_text.img, map->width / 2, map->height - 110);
	}
	mlx_destroy_image(map->img->mlx, map->img->img);
}

int		main_loop(t_map *map)
{
	int		x;
	double	zbuffer[map->width];

	x = 0;
	if (map->save == 0)
		mlx_clear_window(map->img->mlx, map->img->win);
	map->img->img = mlx_new_image(map->img->mlx, map->width, map->height);
	map->img->addr = (int *)mlx_get_data_addr(map->img->img,
	&map->img->bpp, &map->img->line_length, &map->img->endian);
	move(map);
	while (x < map->width)
	{
		calcul_dir(map, &x);
		calc_next_step(map);
		ft_dda(map);
		ft_drawcol(map);
		ft_put_color_img(map, &x);
		zbuffer[x] = map->move->perp_walldist;
		x++;
	}
	put_sprite(map, zbuffer);
	return (0);
}

void	init_struct(char **av)
{
	t_map	map;
	t_color	color;
	t_move	move;
	t_data	img;
	t_key	key;

	color = init_struct_color();
	map = init_struct_map();
	move = init_struct_move();
	key = init_struct_key();
	img.mlx = mlx_init();
	map.color = color;
	map.move = &move;
	map.img = &img;
	map.key = key;
	move.line_height = 0;
	move.old_dirx = 0;
	move.old_planex = 0;
	if (av[2] && ft_strncmp(av[2], "--save", 6) == 0)
		map.save++;
	cub3d(&map, av);
	free_path(&map);
	ft_2dstrdel(&map.origin_map);
}

void	cub3d(t_map *map, char **av)
{
	t_sprite	sprite;
	t_id		id;
	t_text		text;

	id = init_struct_id();
	text = init_struct_text();
	sprite = init_struct_sprite();
	map->sprite = &sprite;
	map->text = text;
	check_info_file(&id, map, av);
	ft_orientation(map);
	map->move->dpos_x = (double)map->posx + 0.5;
	map->move->dpos_y = (double)map->posy + 0.5;
	addr_text(map);
	if (map->save == 0)
	{
		map->img->win = mlx_new_window(map->img->mlx, map->width,
		map->height, "Cub3D");
		mlx_hook(map->img->win, 2, 1L << 0, ft_ispress, map);
		mlx_hook(map->img->win, 3, 1L << 1, ft_isrelease, map);
		mlx_hook(map->img->win, 17, 1L << 17, exit_redcross, map);
	}
	mlx_loop_hook(map->img->mlx, main_loop, map);
	mlx_loop(map->img->mlx);
}

int		main(int ac, char **av)
{
	if (ac == 2 || (ac == 3 && ft_strncmp(av[2], "--save", 6) == 0))
		init_struct(av);
	else
	{
		printf("Error: arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
