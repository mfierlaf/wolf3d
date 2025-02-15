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

#include "../header/wolf3d.h"

void get_text(t_mlx *mlx)
{
	void	*img;
	int		a;

	a = 64;
	img = mlx_xpm_file_to_image(mlx->mlx, "pics/eagle.xpm", &a, &a);
	mlx->tex->north =
	(int*)mlx_get_data_addr(img, &mlx->bpp, &mlx->sl, &mlx->endian);
	ft_printf("1\n");
	img = mlx_xpm_file_to_image(mlx->mlx, "pics/wood.xpm", &a, &a);
	mlx->tex->south =
	(int*)mlx_get_data_addr(img, &mlx->bpp, &mlx->sl, &mlx->endian);
	ft_printf("2\n");
	img = mlx_xpm_file_to_image(mlx->mlx, "pics/colorstone.xpm", &a, &a);
	mlx->tex->west =
	(int*)mlx_get_data_addr(img, &mlx->bpp, &mlx->sl, &mlx->endian);
	ft_printf("3\n");
	img = mlx_xpm_file_to_image(mlx->mlx, "pics/mossy.xpm", &a, &a);
	mlx->tex->east =
	(int*)mlx_get_data_addr(img, &mlx->bpp, &mlx->sl, &mlx->endian);
	ft_printf("4\n");
}

void	ft_init_mlx(t_mlx *mlx)
{
	t_tex *tex;

	tex = ft_memalloc(sizeof(t_tex));
	mlx->tex = tex;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_L,
			WIN_H, "Wolf3D");
	mlx->img = mlx_new_image(mlx->mlx, WIN_L, WIN_H);
	mlx->data = (int *)mlx_get_data_addr(mlx->img,
			&mlx->bpp, &mlx->sl, &mlx->endian);
	mlx->wkey = 0;
	mlx->akey = 0;
	mlx->skey = 0;
	mlx->dkey = 0;
	mlx->qkey = 0;
	mlx->ekey = 0;
}

int		wolf_init(t_map *map)
{
	map->dirx = -1.0;
	map->diry = 0.0;
	map->planx = 0.0;
	map->plany = 0.66;
	map->time = 0.0;
	map->oldtime = 0.0;
	map->color = 0xd4cbe5;
	map->starter = 0;
	map->xpos = map->startx;
	map->ypos = map->starty;
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx *mlx;

	if (ac != 2)
		return (0);
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (ft_exit(1, mlx));
	ft_init_mlx(mlx);
	parser(av[1], mlx);
	draw_sky(mlx);
	draw_floor(mlx);
	wolf_init(mlx->map);
	get_text(mlx);
	//load_textures(mlx);
	raycasting(mlx->map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 17, 0, exit_wolf, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, mlx);
	mlx_hook(mlx->win, 3, (1L << 1), key_release, mlx);
	mlx_loop_hook(mlx->mlx, loop_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
