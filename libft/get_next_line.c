/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:13:20 by mfierlaf          #+#    #+#             */
/*   Updated: 2018/11/23 14:10:12 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stock(char *stock[OPEN_MAX], char **line, int fd)
{
	int	i;

	i = 0;
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	if (line[0][i] == '\n' && line[0][i + 1] != '\0')
	{
		free(stock[fd]);
		stock[fd] = ft_strsub(*line, i + 1, (ft_strlen(*line) - i));
		while (line[0][i] != '\0')
		{
			line[0][i] = '\0';
			i++;
		}
	}
	else
		line[0][i] = '\0';
	return (stock[fd]);
}

static int	ft_return(char **line, int end, char *stock[OPEN_MAX], int flag)
{
	if (end == 0 && line[0][0] == '\0')
	{
		if (!(*line))
			free(*line);
		return (0);
	}
	else if (flag == -1)
	{
		if (!(*line))
			free(*line);
		if (!(*stock))
			free(*stock);
		return (-1);
	}
	else
		return (1);
}

static char	*ft_alloc(char ***line, const int fd, char *stock[OPEN_MAX], int a)
{
	if (a == 0)
		if ((**line = ft_strnew(0)) == NULL)
			return (NULL);
	if (stock[fd] == NULL)
	{
		if ((stock[fd] = ft_strnew(0)) == NULL)
			return (NULL);
	}
	else
	{
		if ((**line = ft_strjoin_free(**line, stock[fd], 3)) == NULL)
			return (NULL);
		if ((stock[fd] = ft_strnew(0)) == NULL)
			return (NULL);
	}
	return (stock[fd]);
}

static int	get_next_line2(const int fd, char **line, int a, int flag)
{
	char		buf[BUFF_SIZE + 1];
	int			end;
	static char	*stock[OPEN_MAX];

	if ((stock[fd] = ft_alloc(&line, fd, stock, a)) == NULL)
		return (ft_return(line, -1, &stock[fd], -1));
	if (ft_strchr(*line, '\n') == NULL)
	{
		end = read(fd, buf, BUFF_SIZE);
		buf[end] = '\0';
		if ((*line = ft_strjoin_free(*line, buf, 1)) == NULL)
			return (ft_return(line, -1, &stock[fd], -1));
		if (ft_strchr(buf, '\n') == NULL && end != 0)
			return (get_next_line2(fd, line, 1, flag));
		else
		{
			if ((stock[fd] = ft_stock(stock, line, fd)) == NULL)
				flag = -1;
			return (ft_return(line, end, &stock[fd], flag));
		}
	}
	if ((stock[fd] = ft_stock(stock, line, fd)) == NULL)
		flag = -1;
	return (ft_return(line, -1, &stock[fd], flag));
}

int			get_next_line(const int fd, char **line)
{
	int		a;
	int		flag;
	char	buf[0];

	if (fd < 0 || read(fd, buf, 0) == -1 || !(line))
		return (-1);
	a = 0;
	flag = 0;
	return (get_next_line2(fd, line, a, flag));
}
