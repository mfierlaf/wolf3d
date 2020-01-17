/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 06:38:57 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/11/28 06:39:24 by mfierlaf         ###   ########.fr       */
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
int	raycasting(t_bham *bham, t_map *map, t_mlx *mlx)
{
	int x;

	x = 0;
	map->dirx = -1;
	map->diry = 0;
	map->planx = 0;
	map->plany = 0.66;
	map->time = 0;
	map->oldtime = 0;
	map->hit = 0;
	map->color = 0xd4cbe5;
	ft_printf("1\n");
	while (x < map->x)
	{
		ft_printf("2\n");
		map->camerax = 2 * x / (double)map->x - 1;
		map->raydirx = map->dirx + map->planx * map->camerax;
		map->raydiry = map->diry + map->plany * map->camerax;
		map->deltadistx = fabs(1 / map->raydirx);
		map->deltadisty = fabs(1/ map->raydiry);
		map->mapx = map->startx;
		map->mapy = map->starty;
		ft_printf("3\n");
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
		ft_printf("4\n");
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
		ft_printf("5\n");
		while (map->hit == 0)
		{
			ft_printf("6\n");
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
			ft_printf("7\n");
			if (map->h[map->mapx + (map->mapy * map->y)] == 1)
				map->hit = 1;
		}
		ft_printf("8\n");
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
		ft_printf("9\n");
		map->lineheight = (int)(map->y / map->perpwalldist);
		map->drawstart = - map->lineheight / 2 + map->y / 2;
        if (map->drawstart < 0)
			map->drawstart = 0;
        map->drawend = map->lineheight / 2 + map->y / 2;
        if (map->drawend >= map->y)
			map->drawend = map->y - 1;
		ft_printf("10\n");
		bresenham(bham, map, mlx);
		ft_printf("11\n");
		x++;
	}
	return (1);
}
