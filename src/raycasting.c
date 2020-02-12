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

int	raycasting(t_map *map, t_mlx *mlx)
{
	int x;

	x = 0;

	while (x < W_W)
	{
		map->camerax = 2.0 * (double)x / (double)W_W - 1.0;
		map->raydirx = map->dirx + (map->planx * map->camerax);
		map->raydiry = map->diry + (map->plany * map->camerax);
		map->deltadistx = fabs(1.0 / map->raydirx);
		map->deltadisty = fabs(1.0 / map->raydiry);
		map->mapx = map->xpos;
		map->mapy = map->ypos;
		map->hit = 0;
		if (map->raydirx < 0.0)
		{
			map->stepx = -1;
			map->sidex = (map->xpos - map->mapx) * map->deltadistx;
		}
		else
		{
			map->stepx = 1;
			map->sidex = (map->mapx + 1.0 - map->xpos) * map->deltadistx;
		}
		if (map->raydiry < 0.0)
		{
			map->stepy = -1;
			map->sidey = (map->ypos - map->mapy) * map->deltadisty;
		}
		else
		{
			map->stepy = 1;
			map->sidey = (map->mapy + 1.0 - map->ypos) * map->deltadisty;
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
			if (map->h[(int)map->mapy][(int)map->mapx] == '1')
				map->hit = 1;
		}
		if (map->side == 0)
		{
			map->perpwalldist = ((double)map->mapx - (double)map->xpos +
					(double)(1.0 - (double)map->stepx) / 2.0) / map->raydirx;
		}
		else
		{
			map->perpwalldist = ((double)map->mapy - (double)map->ypos +
					(double)(1.0 - (double)map->stepy) / 2.0) / map->raydiry;
		}
		map->lineheight = (int)(WIN_H / map->perpwalldist);
		draw_wall(map, mlx);
		x++;
	}
	return (1);
}
