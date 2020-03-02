/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:36:44 by mfierlaf          #+#    #+#             */
/*   Updated: 2020/02/25 16:36:46 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

static	void	right(t_mlx *mlx)
{
	if (mlx->dkey == 1)
	{
		mlx->map->olddir = mlx->map->dirx;
		mlx->map->dirx = mlx->map->dirx * cos(-ROTATE) -
		mlx->map->diry * sin(-ROTATE);
		mlx->map->diry = mlx->map->olddir * sin(-ROTATE) +
		mlx->map->diry * cos(-ROTATE);
		mlx->map->oldplan = mlx->map->planx;
		mlx->map->planx = mlx->map->planx * cos(-ROTATE) -
		mlx->map->plany * sin(-ROTATE);
		mlx->map->plany = mlx->map->oldplan * sin(-ROTATE) +
		mlx->map->plany * cos(-ROTATE);
	}
}

static	void	left(t_mlx *mlx)
{
	if (mlx->akey == 1)
	{
		mlx->map->olddir = mlx->map->dirx;
		mlx->map->dirx = mlx->map->dirx * cos(ROTATE) -
		mlx->map->diry * sin(ROTATE);
		mlx->map->diry = mlx->map->olddir * sin(ROTATE) +
		mlx->map->diry * cos(ROTATE);
		mlx->map->oldplan = mlx->map->planx;
		mlx->map->planx = mlx->map->planx * cos(ROTATE) -
		mlx->map->plany * sin(ROTATE);
		mlx->map->plany = mlx->map->oldplan * sin(ROTATE) +
		mlx->map->plany * cos(ROTATE);
	}
}

int				loop_hook(t_mlx *mlx)
{
	if (mlx->wkey == 1)
	{
		if (mlx->map->h[(int)(mlx->map->ypos + mlx->map->diry * SPEED)]
		[(int)(mlx->map->xpos)] != '1')
			mlx->map->ypos += mlx->map->diry * SPEED;
		if (mlx->map->h[(int)(mlx->map->ypos)]
		[(int)(mlx->map->xpos + mlx->map->dirx * SPEED)] != '1')
			mlx->map->xpos += mlx->map->dirx * SPEED;
	}
	if (mlx->skey == 1)
	{
		if (mlx->map->h[(int)(mlx->map->ypos - mlx->map->diry * SPEED)]
		[(int)(mlx->map->xpos)] != '1')
			mlx->map->ypos -= mlx->map->diry * SPEED;
		if (mlx->map->h[(int)(mlx->map->ypos)]
		[(int)(mlx->map->xpos - mlx->map->dirx * SPEED)] != '1')
			mlx->map->xpos -= mlx->map->dirx * SPEED;
	}
	right(mlx);
	left(mlx);
	erase_putback(mlx);
	return (0);
}
