/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:54:58 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/12/11 13:55:04 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include "keynote.h"
# include <math.h>
# define WIN_H 1050
# define WIN_L 1680
# define W_W 1680
# define SPEED 0.05
# define ROTATE 0.05

typedef struct	s_tex
{
	void		*img;
	int			*data;
	int			bpp;
	int			sl;
	int			endian;
}				t_tex;

typedef struct 	s_map
{
	int		i;
	int		tmp;
	int		x;
	int		y;
	char	**h;
	double 	dirx;
	double 	diry;
	double 	planx;
	double 	plany;
	double 	time;
	double 	oldtime;
	double 	camerax;
	double 	raydirx;
	double 	raydiry;
	double 	sidex;
	double 	sidey;
	double 	deltadistx;
	double 	deltadisty;
	double	perpwalldist;
	double	ymod;
	double	xmod;
	double	xpos;
	double	ypos;
	double	mapx;
	double	mapy;
	double	olddir;
	double	oldplan;
	double	startx;
	double	starty;
	int		stepx;
	int 	stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		starter;


}				t_map;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			endian;
	int			sl;
	int			bpp;
	int			i_width;
	int			i_height;
	int			wkey;
	int			akey;
	int			skey;
	int			dkey;
	int			qkey;
	int			ekey;
	t_map		*map;
	t_tex		tex[9];
}				t_mlx;
/*
**		raycasting
*/
int				raycasting(t_map *map, t_mlx *mlx);
/*
**		key.c
*/
int				loop_hook(t_mlx *mlx);
int				key_push(int key2, t_mlx *mlx);
int				key_press(int key2, t_mlx *mlx);
int				key_release(int key2, t_mlx *mlx);
/*
**		parsing.c
*/
t_map			*parser(char *map_name);
/*
**		tools.c
*/
int				ft_exit(int flag, void *s);
void			erase_putback(t_mlx *mlx);
/*
**		draw.c
*/
void			draw_floor(t_mlx *mlx);
void			draw_sky(t_mlx *mlx);
int				draw_wall(t_map *map, t_mlx *mlx);
void			minimap(t_map *map, t_mlx *mlx);
/*
**		main.c
*/
int				wolf_init(t_map *map);
/*
**		textures.c
*/
void			load_textures(t_mlx *mlx);
#endif
