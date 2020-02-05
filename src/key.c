/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 01:38:32 by tde-brit          #+#    #+#             */
/*   Updated: 2020/02/05 12:11:38 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"
int			loop_hook(t_mlx *mlx)
{
	if (mlx->wkey == 1)
		mlx->map->ypos = mlx->map->diry * 0.05;
	if (mlx->skey == 1)
		mlx->map->ypos = mlx->map->diry / 0.05;
	if (mlx->akey == 1)
		mlx->map->xpos = mlx->map->dirx / 0.05;
	if (mlx->dkey == 1)
		mlx->map->xpos = mlx->map->dirx * 0.05;
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
	if (key2 == W_KEY)
		mlx->wkey = !mlx->wkey;
	if (key2 == A_KEY)
		mlx->akey = !mlx->akey;
	if (key2 == S_KEY)
		mlx->skey = !mlx->skey;
	if (key2 == D_KEY)
		mlx->dkey = !mlx->dkey;
	return (0);
}

int			key_release(int key2, t_mlx *mlx)
{
	if (key2 == W_KEY)
		mlx->wkey = !mlx->wkey;
	if (key2 == A_KEY)
		mlx->akey = !mlx->akey;
	if (key2 == S_KEY)
		mlx->skey = !mlx->skey;
	if (key2 == D_KEY)
		mlx->dkey = !mlx->dkey;
	return (0);
}
