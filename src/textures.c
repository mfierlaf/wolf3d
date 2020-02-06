/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:43:45 by tde-brit          #+#    #+#             */
/*   Updated: 2020/02/05 15:43:47 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	load_textures(t_mlx *mlx)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	mlx->tex[0].img = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &width, &height);
	mlx->tex[0].data = (int *)mlx_get_data_addr(mlx->tex[0].img, &mlx->tex[0].bpp, &mlx->tex[0].sl, &mlx->tex[0].endian);
	mlx->tex[1].img = mlx_xpm_file_to_image(mlx->mlx, "textures/brick.xpm", &width, &height);
	mlx->tex[1].data = (int *)mlx_get_data_addr(mlx->tex[1].img, &mlx->tex[1].bpp, &mlx->tex[1].sl, &mlx->tex[1].endian);
	//mlx->tex[0].data[i % 32 * mlx->tex[0].sl + ((int)map->starter) % 32 * mlx->tex[0].bpp /4]
}
