/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:59:59 by tde-brit          #+#    #+#             */
/*   Updated: 2019/11/25 14:00:01 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
​
#include "../header/wolf3d.h"
​
static void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_L,
			WIN_H, "Wolf3D");
	mlx->img[0] = mlx_new_image(mlx->mlx, WIN_L, WIN_H);
	mlx->img[1] = mlx_new_image(mlx->mlx, WIN_L, WIN_H);
	mlx->data[0] = (int *)mlx_get_data_addr(mlx->img[0],
			&mlx->bpp, &mlx->sl, &mlx->endian);
	mlx->data[1] = (int *)mlx_get_data_addr(mlx->img[1],
			&mlx->bpp, &mlx->sl, &mlx->endian);
}
​
int			main(int ac, char **av)
{
	t_mlx *mlx;
	int x;
	int y;
​
	x = 0;
​
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (ft_exit(1, mlx));
	ft_init_mlx(mlx);
	ac = 0;
	av = NULL;
​
	mlx_key_hook(mlx->win, key_push, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
