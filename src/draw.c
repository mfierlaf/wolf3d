/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:05:24 by tde-brit          #+#    #+#             */
/*   Updated: 2020/02/05 11:05:24 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	draw_sky(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while(x < WIN_H)
	{
		 y = 0;
		 while(y < WIN_L / 2)
		 {
			mlx->data[x + (y * WIN_H)] = 0x01CAFF;
			y++;
		 }
		 x++;
	}
}

void	draw_floor(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while(x < WIN_H)
	{
		 y = WIN_L / 2;
		 while(y < WIN_L)
		 {
			mlx->data[x + (y * WIN_H)] = 0x926D27;
			y++;
		 }
		 x++;
	}
}
int		draw_wall(t_map *map, t_mlx *mlx)
{
	int	i;

	i = ((WIN_L * WIN_H) / 2);
	i -= ((map->lineheight / 2) * WIN_L);
	if (map->starter >= WIN_L)
		map->starter = 0;
	if (map->lineheight > WIN_H)
	{
		map->lineheight = WIN_H - 1;
		map->starter = 0;
	}
	while (map->lineheight > 0)
	{
		if (map->side == 1)
			mlx->data[i + (int)map->starter] = 0x99f900;
		if (map->side == 0)
			mlx->data[i + (int)map->starter] = 0x0000FF;
		i += WIN_L;
		map->lineheight--;
	}
	map->starter++;
	return (0);
}
