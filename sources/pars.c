/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:16:55 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/23 23:08:35 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_floor_ceiling(t_data *data, int fd)
{
	char *line;
	char **floorceil;
	char **color;

	while (1)
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
			if(put_color(&data->floor, floorceil[0]))
				return (1);
		}

		else if (!ft_strcmp(floorceil[0], "C"))
		{
			if(put_color(&data->ceiling, floorceil[1]))
				return (1);
		}
	}
}
int	put_color(t_color *color, char *floorc)
{
	char **colors;
	colors = ft_split(floorc, ",");
	if (ft_strslen(colors) == 3)
	{
		color->r = ft_atoi(colors[0]);
		color->g = ft_atoi(colors[1]);
		color->b = ft_atoi(colors[2]);
		return(0);
	}
	return (1);
}
