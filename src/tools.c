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

int	ft_exit(int flag, void *s)
{
	if(flag == 1)
	{
		ft_printf("Coudn't malloc a structure\n");
		free(s);
		s = NULL;
		exit(-1);
	}
	return (0);
}
