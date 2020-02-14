/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 02:42:29 by tde-brit          #+#    #+#             */
/*   Updated: 2019/11/28 02:42:30 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

int		ft_exit(int flag, void *s)
{
	if(flag == 1)
	{
		ft_printf("Coudn't malloc a structure\n");
		free(s);
		s = NULL;
		exit(-1);
	}
	return (0);
}

void	erase_putback(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_sky(mlx);
	draw_floor(mlx);
	raycasting(mlx->map, mlx);
	minimap(mlx->map, mlx);
//	printf("%lf %lf\n", mlx->map->dirx, mlx->map->diry);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex[0].img, 500, 500);
}
