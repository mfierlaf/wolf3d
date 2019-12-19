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

#include "wolf3d.h"


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
};

int	raycasting(t_bham bham, t_map *map)
{
	int x;

	x = 0;
	map->dirX = -1;
	map->dirY = 0;
	map->planX = 0;
	map->planY = 0.66;
	map->time = 0;
	map->oldtime = 0;
	map->hit = 0;
	map->color = 0xd4cbe5;
	while (x < map->x)
	{
		map->cameraX = 2 * x / double(map->x) - 1;
		map->raydirX = map->dirX + map->planX * map->cameraX;
		map->raydirY = map->dirY + map->planY * map->cameraX;
		map->deltadistX = abs(1 /raydirX);
		map->deltadistY = abs(1/ raydirY);
		map->mapX = map->startX;
		map->mapY = map->startY;
		if (map->raydirX < 0)
		{
			map->stepX = -1;
			map->sideX = (map->startX - map->mapX) * map->deltadistX;
		}
		else
		{
			map->stepX = 1;
			map->sideX = (map->mapX + 1 - map->startX) * map->deltadistX;
		}
		if (map->raydirY < 0)
		{
			map->stepY = -1;
			map->sideY = (map->startY - map->mapY) * map->deltadistY;
		}
		else
		{
			map->stepY = 1;
			map->sideY = (map->mapY +1 - map->startY) * map->deltadistY;
		}
		while (hit = 0)
		{
			if (map->sideX < map->sideY)
			{
				map->sideX += map->deltadistX;
				map->mapX += map->stepX;
				map->side = 0;
			}
			else
			{
				map->sideY += map->deltadistY;
				map->mapY += map->stepY;
				map->side = 1;
			}
			if (worldMap[map->mapX][map->mapY] > 0)
				hit = 1;
		}
		if (map->side == 0)
		{
			map->perpWallDist = (map->mapX - map->startX +
				(1 - map->stepX) / 2) / map->raydirX;
		}
        else
		{
			map->perpWallDist = (map->mapY - map->startY +
				(1 - map->stepY) / 2) / map->raydirY;
		}
		map->linesheight = (int)(map->y / map->perpwalldist);
		map->drawstart = - map->lineseight / 2 + map->y / 2;
        if (map->drawstart < 0)
			map->drawstart = 0;
        map->drawend = map->lineheight / 2 + map->y / 2;
        if (map->drawend >= map->y)
			map->drawend = map->y - 1;
		bresenham(bham, map);
	}
	return (1);
}
