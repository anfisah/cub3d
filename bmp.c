/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:41:21 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:09 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

void	write_int(int fd, int i, int size)
{
	write(fd, &i, size);
}

void	bmp_header(t_map *map, int fd)
{
	int size_file;

	size_file = map->width * map->height * 4 + 54;
	write(fd, "BM", 2);
	write_int(fd, size_file, 4);
	write_int(fd, 0, 2);
	write_int(fd, 0, 2);
	write_int(fd, 54, 4);
}

void	dib_header(t_map *map, int fd)
{
	write_int(fd, 40, 4);
	write_int(fd, map->width, 4);
	write_int(fd, map->height, 4);
	write_int(fd, 1, 2);
	write_int(fd, map->img->bpp, 2);
	write_int(fd, 0, 4);
	write_int(fd, 0, 4);
	write_int(fd, 0, 4);
	write_int(fd, 0, 4);
	write_int(fd, 0, 4);
	write_int(fd, 0, 4);
}

void	bmp(t_map *map)
{
	int fd;
	int i;

	fd = open("img_saved.bmp", O_TRUNC | O_CREAT | O_RDWR, 0777);
	i = map->height;
	bmp_header(map, fd);
	dib_header(map, fd);
	while (i >= 0)
		write(fd, map->img->addr + (i-- * map->width), map->width * 4);
	exit(EXIT_SUCCESS);
}
