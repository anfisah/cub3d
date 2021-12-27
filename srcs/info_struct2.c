/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:05:11 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:38:43 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_color		init_struct_color(void)
{
	t_color color;

	color.f_red = 0;
	color.f_green = 0;
	color.f_blue = 0;
	color.c_red = 0;
	color.c_green = 0;
	color.c_blue = 0;
	color.color_ceiling = 0;
	color.color_floor = 0;
	return (color);
}

t_id		init_struct_id(void)
{
	t_id id;

	id.r = 0;
	id.c = 0;
	id.s = 0;
	id.f = 0;
	id.no = 0;
	id.so = 0;
	id.we = 0;
	id.ea = 0;
	return (id);
}
