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

#include "fdf.h"

void	bresenham(t_bham *bham, t_map *map)
{
	mlx->x0 = map->startX;
	mlx->x1 = map->startX;
	mlx->y0 = map->drawstart;
	mlx->y1 = map->drawend;
	bham->dx = abs(mlx->x1 - mlx->x0);
	bham->sx = mlx->x0 < mlx->x1 ? 1 : -1;
	bham->dy = abs(mlx->y1 - mlx->y0);
	bham->sy = mlx->y0 < mlx->y1 ? 1 : -1;
	bham->err = (bham->dx > bham->dy ? bham->dx :
		-bham->dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, map->color);
		if (mlx->x0 == mlx->x1 && mlx->y0 == mlx->y1)
			break ;
		bham->e2 = bham->err;
		if (bham->e2 > -bham->dx)
		{
			bham->err -= bham->dy;
			mlx->x0 += bham->sx;
		}
		if (bham->e2 < bham->dy)
		{
			bham->err += bham->dx;
			mlx->y0 += bham->sy;
		}
	}
}
