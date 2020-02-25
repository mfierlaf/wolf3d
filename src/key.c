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

int				key_push(int key2, t_mlx *mlx)
{
	if (key2 == ESC_KEY)
	{
		free(mlx);
		exit(-1);
	}
	return (0);
}

int				key_press(int key2, t_mlx *mlx)
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

int				key_release(int key2, t_mlx *mlx)
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
