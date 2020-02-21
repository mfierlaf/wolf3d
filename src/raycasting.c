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
int	texsync(t_map *map, t_mlx *mlx)
{
	int y;

	y = map->drawstart;
	if (map->side == 0)
		map->texwallx = map->ypos + map->perpwalldist * map->raydiry;
	else
		map->texwallx = map->xpos + map->perpwalldist * map->raydirx;
	map->texwallx -= floor((map->texwallx));
	map->texx = (int)(map->texwallx * (double)64);
	if(map->side == 0 && map->raydirx > 0)
		map->texx = 64 - map->texx - 1;
	if(map->side == 1 && map->raydiry < 0)
		map->texx = 64 - map->texx - 1;
	map->texstep = 1.0 * 64 / map->lineheight;
	map->texpos = (map->drawstart - WIN_H / 2 + map->lineheight / 2) *map->texstep;
	while (y < map->drawend)
	{
		map->texy = (int)map->texpos & 63;
		map->texpos += map->texstep;
		map->color = mlx->tex[0].data[64 * map->texy + map->texx];
		if(map->side == 1)
			map->color = (map->color >> 1) & 8355711;
		y++;
	}
	return (0);
}
int	raycasting(t_map *map, t_mlx *mlx)
{
	int x;

	x = 0;

	while (x < W_W)
	{
		map->camerax = 2.0 * (double)x / (double)W_W - 1.0;
		map->raydirx = map->dirx + (map->planx * map->camerax);
		map->raydiry = map->diry + (map->plany * map->camerax);
		map->mapx = map->xpos;
		map->mapy = map->ypos;
		map->deltadistx = fabs(1.0 / map->raydirx);
		map->deltadisty = fabs(1.0 / map->raydiry);
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
		if (map->perpwalldist < 1.0 || map->perpwalldist == -0.0)
			map->perpwalldist = 1;
		map->lineheight = (int)(WIN_H / map->perpwalldist);
		map->drawstart = -map->lineheight / 2.0 + WIN_H / 2.0;
		if (map->drawstart < 0)
			map->drawstart = 0;
		map->drawend = map->lineheight / 2.0 + WIN_H / 2.0;
		if (map->drawend >= WIN_H)
			map->drawend = WIN_H;
		texsync(map, mlx);
		draw_wall(map, mlx);
		x++;
	}
	return (1);
}
