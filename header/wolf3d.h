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

typedef struct 	s_map
{
	int		i;
	int		tmp;
	int		x;
	int		y;
	int		startx;
	int		starty;
	char	*h;
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
	int		stepx;
	int 	stepy;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;

}				t_map;

typedef	struct	s_bham
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_bham;
typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img[5];
	int			*data[5];
	int			endian;
	int			sl;
	int			bpp;
	int			i_width;
	int			i_height;
}				t_mlx;
/*
**		raycasting
*/
int				raycasting(t_map *map, t_mlx *mlx);
/*
**		key.c
*/
int				key_push(int key2, t_mlx *mlx);
/*
**		parsing.c
*/
t_map			*parser(char *map_name);
/*
**		tools.c
*/
int				ft_exit(int flag, void *s);
void			bresenham(t_bham *bham, t_map *map, t_mlx *mlx);
/*
**		draw.c
*/
void			draw_floor(t_mlx *mlx);
void			draw_sky(t_mlx *mlx);
void			draw_wall(int x, t_map *map, t_mlx *mlx);
#endif
