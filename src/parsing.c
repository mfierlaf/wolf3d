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
static t_map	*parser_part2(char *line, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;

	if((map->h = (char **)malloc(sizeof(char *) * map->y + 1)) == NULL)
		return(NULL);
	while(line[i])
	{
		x = 0;
		if((map->h[y] = malloc(sizeof(char) * map->x + 1)) == NULL)
			return(NULL);
		map->h[y][map->x] = '\0';
		while(line[i] && line[i] != '\n')
		{
			if (line[i] != ' ')
			{
				map->h[y][x] = line[i];
				x++;
			}
			i++;
		}
		i++;
		y++;
	}
	free(line);
	return (map);
}
t_map			*parser(char *map_name)
{
	int fd;
	t_map *map;
	char *line;
	char *tmp;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
	 	ft_exit(1, map);
	if ((tmp = ft_strnew(0)) == NULL)
		ft_exit(1, map);
	if((fd = open(map_name, O_RDONLY)) < 0)
		return (NULL);
	map->y = 0;
	while(get_next_line(fd, &line) != 0)
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
			if (line[map->i] == '0' || line[map->i] == '1' || line[map->i] == '2')
				map->x++;
			map->i++;
		}
		if (map->tmp != 0 && map->x != map->tmp)
			return (NULL);
		tmp = ft_strjoin_free(tmp, ft_strjoin_free(line, "\n", 1), 3);
		map->y++;
	}
	map = parser_part2(tmp, map);
	return (map);
}
