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
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, WIN_L, WIN_H);
	mlx->data = (int *)mlx_get_data_addr(mlx->img,
		&mlx->bpp, &mlx->sl, &mlx->endian);
	draw_sky(mlx);
	draw_floor(mlx);
	raycasting(mlx->map, mlx);
	minimap(mlx->map, mlx);
//	printf("%lf %lf\n", mlx->map->dirx, mlx->map->diry);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex[0].img, 500, 500);
}
