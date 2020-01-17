/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:42:06 by tde-brit          #+#    #+#             */
/*   Updated: 2019/08/03 13:11:51 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	bresenham(t_bham *bham, t_map *map, t_mlx *mlx)
{
	bham->x0 = map->startx;
	bham->x1 = map->startx;
	bham->y0 = map->drawstart;
	bham->y1 = map->drawend;
	bham->dx = abs(bham->x1 - bham->x0);
	bham->sx = bham->x0 < bham->x1 ? 1 : -1;
	bham->dy = abs(bham->y1 - bham->y0);
	bham->sy = bham->y0 < bham->y1 ? 1 : -1;
	bham->err = (bham->dx > bham->dy ? bham->dx :
		-bham->dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, bham->x0, bham->y0, 0xFF00FF);
		if (bham->x0 == bham->x1 && bham->y0 == bham->y1)
			break ;
		bham->e2 = bham->err;
		if (bham->e2 > -bham->dx)
		{
			bham->err -= bham->dy;
			bham->x0 += bham->sx;
		}
		if (bham->e2 < bham->dy)
		{
			bham->err += bham->dx;
			bham->y0 += bham->sy;
		}
	}
}
