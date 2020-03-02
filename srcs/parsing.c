/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 02:23:14 by tde-brit          #+#    #+#             */
/*   Updated: 2019/11/28 02:23:15 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

static int		verify(t_map *map)
{
	int i;

	i = 0;
	while (i < map->x)
	{
		if (map->data[0][i] == 48 || map->data[map->y - 1][i] == 48)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->y)
	{
		if (map->data[i][0] == 48 || map->data[i][map->x - 1] == 48)
			return (0);
		i++;
	}
	return (1);
}

static t_map	*bouclegetnextline(char *line, t_map *map)
{
	map->tmp = map->x;
	map->i = 0;
	map->x = 0;
	while (line[map->i])
	{
		if (line[map->i] == '2')
		{
			map->startx = (double)map->x;
			map->starty = (double)map->y;
		}
		if (line[map->i] == '0' || line[map->i] == '1' ||
		line[map->i] == '2')
			map->x++;
		map->i++;
	}
	if (map->tmp != 0 && map->x != map->tmp)
		return (NULL);
	return (map);
}

static t_map	*boucleline(char *line, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (line[i])
	{
		x = 0;
		if ((map->data[y] = malloc(sizeof(char) * map->x + 1)) == NULL)
			return (NULL);
		map->data[y][map->x] = '\0';
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != ' ')
			{
				map->data[y][x] = line[i];
				x++;
			}
			i++;
		}
		i++;
		y++;
	}
	return (map);
}

static t_map	*parser_part2(char *line, t_map *map)
{
	if ((map->data = (char **)malloc(sizeof(char *) * map->y + 1)) == NULL)
		return (NULL);
	map = boucleline(line, map);
	free(line);
	return (map);
}

void			parser(char *map_name, t_mlx *mlx)
{
	int		fd;
	t_map	*map;
	char	*line;
	char	*tmp;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		ft_exit(1, mlx);
	map->data = NULL;
	if ((tmp = ft_strnew(0)) == NULL)
		ft_exit(0, mlx);
	if ((fd = open(map_name, O_RDONLY)) < 0 || read(fd, tmp, 0) < 0)
		ft_exit(1, mlx);
	map->y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		map = bouclegetnextline(line, map);
		tmp = ft_strjoin_free(tmp, ft_strjoin_free(line, "\n", 1), 3);
		map->y++;
	}
	map = parser_part2(tmp, map);
	close(fd);
	mlx->map = map;
	if (verify(map) == 0)
		ft_exit(2, mlx);
}
