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

t_map	*parser(char *map_name)
{
	int fd;
	t_map *map;
	char *line;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
	 	ft_exit(1, map);
	if ((map->h = ft_strnew(0)) == NULL)
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
				map->startx = map->x;
				map->starty = map->y;
			}
			if (line[map->i] == '0' || line[map->i] == '1' || line[map->i] == '2')
				map->x++;
			map->i++;
		}
		if (map->tmp != 0 && map->x != map->tmp)
			return (NULL);
		map->h = ft_strjoin_free(map->h, ft_strjoin_free(line, " ", 1), 3);
		map->y++;
	}
	return (map);
}
