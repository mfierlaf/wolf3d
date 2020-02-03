/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 06:38:57 by mfierlaf          #+#    #+#             */
/*   Updated: 2020/02/03 13:44:35 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

/*
   int worldMap[mapWidth][mapHeight]=
   {
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
   };*/
int	raycasting(t_map *map, t_mlx *mlx)
{
	int x;
	int	y;

	y = 0;
	x = 0;
	map->dirx = -1;
	map->diry = 0;
	map->planx = 0;
	map->plany = 0.66;
	map->time = 0;
	map->oldtime = 0;
	map->hit = 0;
	map->color = 0xd4cbe5;
	while (x < WIN_H)
	{
		map->camerax = 2 * x / (double)map->x - 1;
		map->raydirx = map->dirx + map->planx * map->camerax;
		map->raydiry = map->diry + map->plany * map->camerax;
		map->deltadistx = fabs(1 / map->raydirx);
		map->deltadisty = fabs(1/ map->raydiry);
		map->mapx = map->startx;
		map->mapy = map->starty;
		if (map->raydirx < 0)
		{
			map->stepx = -1;
			map->sidex = (map->startx - map->mapx) * map->deltadistx;
		}
		else
		{
			map->stepx = 1;
			map->sidex = (map->mapx + 1 - map->startx) * map->deltadistx;
		}
		if (map->raydiry < 0)
		{
			map->stepy = -1;
			map->sidey = (map->starty - map->mapy) * map->deltadisty;
		}
		else
		{
			map->stepy = 1;
			map->sidey = (map->mapy +1 - map->starty) * map->deltadisty;
		}
		while (map->hit == 0)
		{
			if (map->sidex < map->sidey)
			{
				map->sidex += map->deltadistx;
				map->mapx += map->stepx;
				map->side = 0;
			}
			else
			{
				map->sidey += map->deltadisty;
				map->mapy += map->stepy;
				map->side = 1;
			}
			if (map->h[map->mapx + (map->mapy * map->x)] == 1)
				map->hit = 1;
		}
		if (map->side == 0)
		{
			map->perpwalldist = (map->mapx - map->startx +
					(1 - map->stepx) / 2) / map->raydirx;
		}
		else
		{
			map->perpwalldist = (map->mapy - map->starty +
					(1 - map->stepy) / 2) / map->raydiry;
		}
		map->lineheight = (int)(map->y / map->perpwalldist);
		map->drawstart = ((-map->lineheight) / 2 + map->y / 2) * map->ymod;
		if (map->drawstart < 0)
			map->drawstart = 0;
		map->drawend = (map->lineheight / 2 + map->y / 2) * map->ymod;
		if (map->drawend >= map->y)
			map->drawend = map->y - 1;
		map->drawstart++;
		if (map->hit == 1)
			{
				draw_wall(x, map, mlx);
				map->hit = 0;
			}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0] , 0 , 0);
	return (1);
}
