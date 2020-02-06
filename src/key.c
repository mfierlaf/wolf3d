/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 01:38:32 by tde-brit          #+#    #+#             */
/*   Updated: 2020/02/05 16:44:21 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"
int			loop_hook(t_mlx *mlx)
{
	if (mlx->wkey == 1)
	{
		if (mlx->map->h[(int)(mlx->map->ypos + mlx->map->diry * 0.2)][
		(int)(mlx->map->xpos + mlx->map->dirx * 0.2)] == '0')
			{
				mlx->map->ypos += mlx->map->diry * 0.05;
				mlx->map->xpos += mlx->map->dirx * 0.05;
			}
	}
	if (mlx->skey == 1)
	{
		if (mlx->map->h[(int)(mlx->map->ypos - mlx->map->diry * 0.2)][(int)(mlx->map->xpos)] == '0')
			mlx->map->ypos -= mlx->map->diry * 0.05;
		if (mlx->map->h[(int)(mlx->map->ypos)][(int)(mlx->map->xpos - mlx->map->dirx * 0.2)] == '0')
			mlx->map->xpos -= mlx->map->dirx * 0.05;
	}
	if (mlx->dkey == 1)
	{
		mlx->map->olddir = mlx->map->dirx;
		mlx->map->dirx = mlx->map->dirx * cos(-0.05) - mlx->map->diry * sin(-0.05);
		mlx->map->diry = mlx->map->olddir * sin(-0.05) + mlx->map->olddir * cos(-0.05);
		mlx->map->oldplan = mlx->map->planx;
		mlx->map->planx = mlx->map->planx * cos(-0.05) - mlx->map->plany * sin(-0.05);
		mlx->map->plany = mlx->map->oldplan * sin(-0.05) + mlx->map->plany * cos(-0.05);
	}
	if (mlx->akey == 1)
	{

		mlx->map->olddir = mlx->map->dirx;
		mlx->map->dirx = mlx->map->dirx * cos(0.05) - mlx->map->diry * sin(0.05);
		mlx->map->diry = mlx->map->olddir * sin(0.05) + mlx->map->olddir * cos(0.05);
		mlx->map->oldplan = mlx->map->planx;
		mlx->map->planx = mlx->map->planx * cos(0.05) - mlx->map->plany * sin(0.05);
		mlx->map->plany = mlx->map->oldplan * sin(0.05) + mlx->map->plany * cos(0.05);
	}
	erase_putback(mlx);
	return (0);
}

int			key_push(int key2, t_mlx *mlx)
{
	if (key2 == ESC_KEY)
	{
		free(mlx);
		exit(-1);
	}
	return (0);
}

int			key_press(int key2, t_mlx *mlx)
{
	if (key2 == ESC_KEY)
	{
		free(mlx);
		exit(-1);
	}
	if (key2 == W_KEY)
		mlx->wkey = 1;
	if (key2 == A_KEY)
		mlx->akey = 1;
	if (key2 == S_KEY)
		mlx->skey = 1;
	if (key2 == D_KEY)
		mlx->dkey = 1;
	return (0);
}

int			key_release(int key2, t_mlx *mlx)
{
	if (key2 == W_KEY)
		mlx->wkey = 0;
	if (key2 == A_KEY)
		mlx->akey = 0;
	if (key2 == S_KEY)
		mlx->skey = 0;
	if (key2 == D_KEY)
		mlx->dkey = 0;
	return (0);
}
