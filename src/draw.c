#include "../header/wolf3d.h"

void	draw_sky(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while(x < WIN_H)
	{
		 y = 0;
		 while(y < WIN_L / 2)
		 {
			mlx->data[0][x + (y * WIN_H)] = 0xFF0000;
			y++;
		 }
		 x++;
	}
}

void	draw_floor(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while(x < WIN_H)
	{
		 y = WIN_L / 2;
		 while(y < WIN_L)
		 {
			mlx->data[0][x + (y * WIN_H)] = 0x0000FF;
			y++;
		 }
		 x++;
	}
}
void	draw_wall(int x, t_map *map, t_mlx *mlx)
{
	while(--map->drawstart >= map->drawend)
		mlx->data[0][x + (map->drawstart * WIN_H)] = 0x00FF00;
}
