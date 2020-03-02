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

static void	raydir(t_map *map)
{
	if (map->raydirx < 0.0)
	{
		map->stepx = -1;
		map->sidex = (map->xpos - (double)map->mapx) * map->deltadistx;
	}
	else
	{
		map->stepx = 1;
		map->sidex = ((double)map->mapx + 1.0 - map->xpos) * map->deltadistx;
	}
	if (map->raydiry < 0.0)
	{
		map->stepy = -1;
		map->sidey = (map->ypos - (double)map->mapy) * map->deltadisty;
	}
	else
	{
		map->stepy = 1;
		map->sidey = ((double)map->mapy + 1.0 - map->ypos) * map->deltadisty;
	}
}

static void	init(t_map *map, int x)
{
	map->camerax = 2.0 * (double)x / (double)W_W - 1.0;
	map->raydirx = map->dirx + (map->planx * map->camerax);
	map->raydiry = map->diry + (map->plany * map->camerax);
	map->mapx = (int)map->xpos;
	map->mapy = (int)map->ypos;
	map->deltadistx = fabs(1.0 / map->raydirx);
	map->deltadisty = fabs(1.0 / map->raydiry);
	map->hit = 0;
}

static void	hit(t_map *map)
{
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
		if (map->data[(int)map->mapy][(int)map->mapx] == '1')
			map->hit = 1;
	}
}

int			raycasting(t_map *map, t_mlx *mlx)
{
	int x;

	x = 0;
	while (x < W_W)
	{
		init(map, x);
		raydir(map);
		hit(map);
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
		if (map->perpwalldist < 1.0 || map->perpwalldist == -0.0)
			map->perpwalldist = 1;
		map->lineheight = (int)(WIN_H / map->perpwalldist);
		draw_wall(map, mlx);
		x++;
	}
	return (1);
}
