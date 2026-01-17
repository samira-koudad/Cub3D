/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/17 21:58:15 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int check_texture()

// finish ny .cub
int check_file(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

//main parsing
int	parsing(s_data *data, char *path)
{
	int fd;
	if (check_file(path)) //finish by .cub
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (check_texture(data, fd)) //using gnl
		return (1);
	if (check_floor_ceiling(fd)) //using gnl
		return (1);
	if (check_map(fd)) //using gnl
		return (1);



	return (0);
}
