/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:18:26 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 12:00:21 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	put_resolution(t_map *map, char *line, int *i)
{
	map->width = check_resolution(line, i);
	if (map->width < 0)
		map->error_resolution++;
	if (map->width > 2560)
		map->width = 2560;
	if (map->width < 200)
		map->width = 200;
	map->height = check_resolution(line, i);
	if (map->height < 0)
		map->error_resolution++;
	if (map->height > 1440)
		map->height = 1440;
	if (map->height < 200)
		map->height = 200;
	while (map->width % 64 != 0)
		map->width++;
	while (map->height % 64 != 0)
		map->height++;
}

void	resolution(char *line, t_id *id, t_map *map, int *i)
{
	int len;

	len = 0;
	*id = count_id(line, i, *id);
	(*i)++;
	while (line[*i] != '\0')
	{
		if (line[*i] == (ft_isdigit(line[*i]) == 1) && line[*i] != ' ')
			map->error_resolution++;
		(*i)++;
		len++;
	}
	(*i) -= len;
	put_resolution(map, line, i);
	while (line[*i] != '\0')
	{
		if (line[*i] != ' ')
			map->error_resolution++;
		(*i)++;
	}
}

int		gnl(int fd, char *line, t_id *id, t_map *map)
{
	int		gnl;
	int		i;

	map->fill_map = ft_calloc(1, 1);
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		i = 0;
		check_infos(line, &i, id);
		if (line[i] == 'R')
			resolution(line, id, map, &i);
		else if (id_path(line, &i) == 1)
		{
			*id = count_id(line, &i, *id);
			i++;
			check_path(line, &i, map);
		}
		else if (line[i] == 'F' || line[i] == 'C')
			put_color(line, id, map, &i);
		else if (all_id(id) == 1)
			map->fill_map = ft_strjoin_map(map->fill_map, line);
		free(line);
	}
	map->fill_map = ft_strjoin(map->fill_map, line);
	free(line);
	return (i);
}

void	parsing(t_map *map, t_id *id, int fd)
{
	int		posx;
	int		posy;
	char	*line;
	int		i;

	map->origin_map = NULL;
	line = NULL;
	i = gnl(fd, line, id, map);
	map->map_split = ft_split(map->fill_map, '\n');
	map->origin_map = ft_split(map->fill_map, '\n');
	free(map->fill_map);
	posx = 0;
	posy = 0;
	find_pos(map->map_split, &posx, &posy, map);
	check_error2(map, id);
	map->origin_map[posx][posy] = '0';
	check_map(map->map_split);
	flood_fill(map->map_split, posx, posy, map);
	ft_2dstrdel(&map->map_split);
	check_errors(map);
}

void	check_info_file(t_id *id, t_map *map, char **av)
{
	int		fd;
	int		len_file;
	char	*name_file;

	if ((fd = open(av[1], O_RDWR)) == -1)
	{
		printf("open() error");
		exit(EXIT_FAILURE);
	}
	name_file = ft_strdup(av[1]);
	len_file = ft_strlen(name_file);
	if (name_file[len_file - 1] != 'b' && name_file[len_file - 2] != 'u' &&
		name_file[len_file - 3] != 'c' && name_file[len_file - 4] != '.')
	{
		free(name_file);
		printf("Error : file format");
		exit(EXIT_FAILURE);
	}
	free(name_file);
	parsing(map, id, fd);
	if ((close(fd)) == -1)
	{
		printf("close() error");
		exit(EXIT_FAILURE);
	}
}
