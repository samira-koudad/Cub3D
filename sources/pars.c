/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:16:55 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/25 19:56:24 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_color(t_color *color, char *floorc)
{
	char **colors;

	if (color->r != -1)
		return (1);
	colors = ft_split(floorc, ',');
	if (ft_strslen(colors) == 3)
	{
		if (ft_atoi(colors[0]) >= 0 && ft_atoi(colors[0]) <= 255 && ft_strlen(colors[0]) < 4)
			color->r = ft_atoi(colors[0]);
		else
			return (1);
		if (ft_atoi(colors[1]) >= 0 && ft_atoi(colors[1]) <= 255 && ft_strlen(colors[1]) < 4)
			color->g = ft_atoi(colors[1]);
		else
			return (1);
		if (ft_atoi(colors[2]) >= 0 && ft_atoi(colors[2]) <= 255 && ft_strlen(colors[2]) < 4)
			color->b = ft_atoi(colors[2]);
		else
			return (1);
		return (0);
	}
	return (1);
}
