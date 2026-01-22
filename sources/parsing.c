/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/22 21:50:52 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_texture_line(t_data *data, char *path_texture, int direction)
{
	char *path;

	if (data->textures[direction])
		return (1);
	path = ft_strdup(path_texture);
	if (!path)
		return (1);
	data->textures[direction] = path;
	return (0);
}

int check_texture(t_data *data, int fd)
{
	char	*line;
	char	**strs;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		strs = ft_split_custom(line, " \f\t\n\r\v");
		// strs size == 2
		if (!ft_strcmp(strs[0], "NO"))
			if (parse_texture_line(data, strs[1], N))
				return (1);
		else if (!ft_strcmp(strs[0], "SO"))
			if (parse_texture_line(data, strs[1], S))
				return (1);
		else if (!ft_strcmp(strs[0], "EA"))
			if (parse_texture_line(data, strs[1], E))
				return (1);
		else if (!ft_strcmp(strs[0], "WE"))
			if (parse_texture_line(data, strs[1], W))
				return (1);
		else
			return (1);

		free(line);
	}
	return (0);
}

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
int	parsing(t_data *data, char *path)
{
	int fd;
	if (check_file(path)) //finish by .cub
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (check_texture(data, fd)) //using gnl
		return (1);
	// if (check_floor_ceiling(fd)) //using gnl
	// 	return (1);
	// if (check_map(fd)) //using gnl
	// 	return (1);
	close(fd);


	return (0);
}
