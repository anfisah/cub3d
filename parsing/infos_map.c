/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:18:10 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 11:24:22 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		check_resolution(char *line, int *i)
{
	char	*str;
	int		len;
	int		res;

	(*i)++;
	len = 0;
	res = -1;
	while (line[*i] == ' ')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		len++;
		(*i)++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	(*i) -= len;
	str = res_cpy(line, i, str);
	res = ft_atoi(str);
	free(str);
	return (res);
}

void	check_format(char *str, t_map *map)
{
	int len;

	len = ft_strlen(str);
	if (len < 4)
	{
		printf("Error : Path invalid\n");
		exit(EXIT_FAILURE);
	}
	if (str[len - 1] != 'm')
		map->error_xpm++;
	if (str[len - 2] != 'p')
		map->error_xpm++;
	if (str[len - 3] != 'x')
		map->error_xpm++;
	if (str[len - 4] != '.')
		map->error_xpm++;
}

int		check_path(char *line, int *i, t_map *map)
{
	char	*str;
	int		fd;

	(*i)++;
	str = NULL;
	if (!(str = ft_strtrim(&line[*i], " ")))
		map->error_path++;
	check_format(str, map);
	struct_fill(line, str, map);
	fd = open(str, O_RDWR);
	if (fd < 0)
		map->error_path++;
	if (close(fd) < 0)
		map->error_path++;
	free(str);
	return (0);
}

char	*color2(char *line, int len, int *i)
{
	char	*str;
	int		j;

	j = 0;
	str = calloc(1, len);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		str[j] = line[*i];
		(*i)++;
		j++;
	}
	return (str);
}

int		check_color(char *line, int *i, t_map *map)
{
	int		len;
	char	*str;
	int		rgb;

	space(line, i);
	if (line[*i] == ',')
		(*i)++;
	space(line, i);
	len = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		len++;
		(*i)++;
	}
	error_rgb(line, *i, map);
	if (len < 1 || len > 3)
		map->no_color++;
	(*i) -= len;
	str = color2(line, len, i);
	rgb = ft_atoi(str);
	if (rgb < 0 || rgb > 255)
		map->no_color++;
	free(str);
	str = NULL;
	return (rgb);
}
