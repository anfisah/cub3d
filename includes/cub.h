/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:13:57 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/04 13:06:09 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"
# define ROT 0.05
# define MOVESPEED 0.09
# define ESC 53
# define MLEFT 0
# define NORTH 13
# define SOUTH 1
# define MRIGHT 2
# define UP 126
# define DOWN 125
# define TLEFT 123
# define TRIGHT 124
# define HUD 3

typedef struct	s_id
{
	int			r;
	int			c;
	int			s;
	int			f;
	int			no;
	int			so;
	int			we;
	int			ea;
}				t_id;

typedef struct	s_sprite
{
	int			screenx;
	int			spriteh;
	int			drawstarty;
	int			drawendy;
	int			spritew;
	int			drawstartx;
	int			drawendx;
	int			textx;
	int			d;
	int			texty;
	int			stripe;
	int			color;
	double		sprite_x;
	double		sprite_y;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transfx;
	double		transfy;
	double		spritedist;
}				t_sprite;

typedef struct	s_text
{
	int			tex_x;
	int			tex_y;
	int			textw;
	int			texth;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		wall;
	double		step;
	double		tex_pos;
}				t_text;

typedef struct	s_key
{
	int			k_turn_left;
	int			k_turn_right;
	int			k_up;
	int			k_down;
	int			k_move_left;
	int			k_move_right;
	int			k_north;
	int			k_south;
	int			k_esc;
	int			hud;
}				t_key;

typedef struct	s_move
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera;
	double		ray_dirx;
	double		ray_diry;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		perp_walldist;
	double		dpos_x;
	double		dpos_y;
	double		old_dirx;
	double		old_planex;
}				t_move;

typedef struct	s_data
{
	int			bpp;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
}				t_data;

typedef struct	s_tex
{
	int			textw;
	int			texth;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*img;
}				t_tex;

typedef struct	s_texture
{
	t_tex		n_text;
	t_tex		s_text;
	t_tex		e_text;
	t_tex		w_text;
	t_tex		sp_text;
	t_tex		life_text;
	t_tex		knife_text;
}				t_texture;

typedef struct	s_color
{
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
	int			color_ceiling;
	int			color_floor;
}				t_color;

typedef struct	s_map
{
	int			width;
	int			height;
	int			personnage;
	int			posx;
	int			posy;
	int			no_color;
	int			error_path;
	int			error_resolution;
	int			error_xpm;
	int			numsprite;
	int			save;
	char		**map_split;
	char		**origin_map;
	char		*fill_map;
	char		orientation;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	char		*s_text;
	t_move		*move;
	t_data		*img;
	t_key		key;
	t_text		text;
	t_texture	text_used;
	t_sprite	*sprite;
	t_color		color;
}				t_map;

/*
** Initialization structures
*/
t_map			init_struct_map(void);
t_id			init_struct_id(void);
t_color			init_struct_color(void);
t_move			init_struct_move(void);
t_key			init_struct_key(void);
t_id			count_id(char *line, int *i, t_id id);
t_text			init_struct_text(void);
t_sprite		init_struct_sprite(void);
/*
** Get_next_line
*/
int				ft_findchr(char *s, char c);
int				get_next_line(int fd, char **line);
char			*ft_substr_free(char *s, unsigned int start, size_t len);
char			*read_line(int fd, char *str, int *res);
/*
** Parsing
*/
int				check_path(char *line, int *i, t_map *map);
int				check_resolution(char *line, int *i);
int				ft_isspawn(char c);
int				find_pos(char **map_split, int *posx, int *posy, t_map *map);
int				check_color(char *line, int *i, t_map *map);
int				check_errors(t_map *map);
int				put_color(char *line, t_id *id, t_map *map, int *i);
int				check_error2(t_map *map, t_id *id);
int				check_map(char **map_split);
int				id_path(char *line, int *i);
int				gnl(int fd, char *line, t_id *id, t_map *map);
int				error_rgb(char *line, int i, t_map *map);
int				check_color(char *line, int *i, t_map *map);
int				check_infos(char *line, int *i, t_id *id);
int				all_id(t_id *id);
int				ft_sstrlen(char **tab);
int				flood_fill(char **my_map, int x, int y, t_map *map);
char			*ft_strjoin_map(char const *s1, char const *s2);
char			*ft_len(char *line, int *i, int len, t_map *map);
char			*color2(char *line, int len, int *i);
char			*res_cpy(char *line, int *i, char *str);
void			check_info_file(t_id *id, t_map *map, char **av);
void			space(char *line, int *i);
void			check_format(char *str, t_map *map);
void			parsing(t_map *map, t_id *id, int fd);
void			resolution(char *line, t_id *id, t_map *map, int *i);
void			struct_fill(char *line, char *str, t_map *map);
void			error_malloc(t_map *map);
void			free_path(t_map *map);
/*
** calculs + sprites + textures
*/
int				ft_close(int keycode, t_map *map);
int				key_hook_close(int keycode, t_map *map);
int				exit_redcross(void);
int				main_loop(t_map *map);
int				ft_ispress(int keycode, t_map *map);
int				ft_isrelease(int keycode, t_map *map);
void			ft_print_struct(t_move move, t_map map);
void			turn_right(t_map *map);
void			turn_left(t_map *map);
void			move_south(t_map *map);
void			move_north(t_map *map);
void			move(t_map *map);
void			calc_next_step(t_map *map);
void			ft_dda(t_map *map);
void			ft_drawcol(t_map *map);
void			ft_put_color_img(t_map *map, int *x);
void			put_textures(t_map *map, int *y, int *x);
void			nb_sprites(t_map *map);
void			sortsprites(t_map *map);
void			pos_sprites(t_map *map);
void			write_int(int fd, int i, int size);
void			bmp_header(t_map *map, int fd);
void			dib_header(t_map *map, int fd);
void			bmp(t_map *map);
void			cub3d(t_map *map, char **av);
void			info_sprite(t_map *map);
void			sprite_camera(t_map *map, double *zbuffer);
void			ft_orientation(t_map *map);
void			addr_text(t_map *map);
void			addr_sprites(t_map *map);
void			calcul_sprite(t_map *map, int *i);
void			init_struct(char **av);
void			calcul_dir(t_map *map, int *x);

#endif
