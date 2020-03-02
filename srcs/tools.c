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

int		ft_exit(int flag, t_mlx *mlx)
{
	if (flag == 0)
	{
		ft_printf("Coudn't malloc a structure\n");
		free(mlx);
		exit(1);
	}
	else if (flag == 1)
	{
		perror("Couldn't open map ");
		free(mlx);
		exit(1);
	}
	else if (flag == 2)
	{
		ft_printf("Invalid map\n");
		free_map(mlx->map);
		free(mlx);
		exit(1);
	}
	return (0);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (map->data != NULL)
	{
		while (i < map->y)
			free(map->data[i++]);
		free(map->data);
	}
	free(map);
}

int		exit_wolf(t_mlx *mlx)
{
	free_map(mlx->map);
	free(mlx);
	exit(0);
	return (0);
}

void	erase_putback(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_sky(mlx);
	draw_floor(mlx);
	raycasting(mlx->map, mlx);
	minimap(mlx->map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
