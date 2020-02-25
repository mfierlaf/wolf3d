/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:55:29 by mfierlaf          #+#    #+#             */
/*   Updated: 2020/02/05 15:55:32 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

static	void	draw_player(int h, int l, t_mlx *mlx, t_map *map)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < (h + ((WIN_H / 5) / (map->y))))
	{
		tmp = l;
		while (tmp < l + ((WIN_L / 5) / (map->x)))
		{
			mlx->data[tmph * WIN_L + tmp] = 0x0000FF;
			tmp++;
		}
		tmph++;
	}
}

static void		draw_mini_wall(int h, int l, t_mlx *mlx, t_map *map)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < (h + ((WIN_H / 5) / (map->y))))
	{
		tmp = l;
		while (tmp < l + ((WIN_L / 5) / (map->x)))
		{
			mlx->data[tmph * WIN_L + tmp] = 0x6D071A;
			tmp++;
		}
		tmph++;
	}
}

static void		draw_mini_floor(int h, int l, t_mlx *mlx, t_map *map)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < h + ((WIN_H / 5) / (map->y)))
	{
		tmp = l;
		while (tmp < l + ((WIN_L / 5) / (map->x)))
		{
			mlx->data[tmph * WIN_L + tmp] = 0xFFFFFF;
			tmp++;
		}
		tmph++;
	}
}

void			minimap(t_map *map, t_mlx *mlx)
{
	int h;
	int l;
	int i;
	int j;

	h = 0;
	l = 0;
	i = 0;
	while (i < map->y && map->h[i])
	{
		j = 0;
		l = 0;
		while (j++ < map->x && map->h[i][j])
		{
			if (i == (int)map->ypos && j == (int)map->xpos)
				draw_player(h, l, mlx, map);
			else if (map->h[i][j] == '1')
				draw_mini_wall(h, l, mlx, map);
			else
				draw_mini_floor(h, l, mlx, map);
			l += ((WIN_L / 5) / (map->x));
		}
		i++;
		h += ((WIN_H / 5) / (map->y));
	}
}
