/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:16:55 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/25 16:49:12 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_floor_ceiling(t_data *data, int fd)
{
	char *line;
	char **floorceil;
	//char **color;
	int i = 0;

	while (i < 2)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		floorceil = ft_split_custom(line, " \f\t\n\v\r");
		free(line);
		if (ft_strslen(floorceil) == 0)
			continue ;// free strs
		if (ft_strslen(floorceil) != 2)
			return (1);
		if (!ft_strcmp(floorceil[0], "F"))
		{
			if(put_color(&data->floor, floorceil[1]))
				return (puts("err 1"),1);
		}
		else if (!ft_strcmp(floorceil[0], "C"))
		{
			if(put_color(&data->ceiling, floorceil[1]))
				return (puts("err 2"),1);
		}
		i++;
	}
	// printf("%d, %d, %d \n" , data->floor.r, data->floor.g, data->floor.b);
	// printf("%d, %d, %d \n" , data->ceiling.r, data->ceiling.g, data->ceiling.b);
	return (0);
}

int	put_color(t_color *color, char *floorc)
{
	char **colors;
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
