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

static	void	draw_player(int h, int spacex, int l, int spacey, t_mlx *mlx)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < (h + spacey))
	{
		tmp = l;
		while (tmp < l + spacex)
		{
			mlx->data[tmph * WIN_L + tmp] = 0x0000FF;
			tmp++;
		}
		tmph++;
	}
}

static void	draw_mini_wall(int h, int spacex, int l, int spacey, t_mlx *mlx)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < (h + spacey))
	{
		tmp = l;
		while (tmp < l + spacex)
		{
			mlx->data[tmph * WIN_L + tmp] = 0x6D071A;
			tmp++;
		}
		tmph++;
	}
}

static void	draw_mini_floor(int h, int spacex, int l, int spacey, t_mlx *mlx)
{
	int tmp;
	int tmph;

	tmph = h;
	while (tmph < h + spacey)
	{
		tmp = l;
		while (tmp < l + spacex)
		{
			mlx->data[tmph * WIN_L + tmp] = 0xFFFFFF;
			tmp++;
		}
		tmph++;
	}
}

void minimap(t_map *map, t_mlx *mlx)
{
	int h;
	int l;
	int spacex;
	int spacey;
	int i;
	int j;

	spacex = ((WIN_L / 5) / (map->x));
	spacey = ((WIN_H / 5) / (map->y));
	h = 0;
	l = 0;
	i = 0;
	while (i < map->y && map->h[i])
	{
		ft_printf("1\n");
		j = 0;
		l = 0;
		while (j < map->x  && map->h[i][j])
		{
			ft_printf("2\n");
			if ((double)i == map->ypos && (double)j == map->xpos)
				draw_player(h, spacex, l, spacey, mlx);
			else if (map->h[i][j] == '1')
				draw_mini_wall(h, spacex, l, spacey, mlx);
			else
				draw_mini_floor(h, spacex, l, spacey, mlx);
			j++;
			l += spacex;
		}
		i++;
		h += spacey;
	}
}
