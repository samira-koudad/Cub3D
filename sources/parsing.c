/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/23 23:09:36 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_empty(char **strs, int expected_len)
{
	int	i;
	int	nb_not_null;

	i = 0;
	nb_not_null = 0;
	while (i < expected_len)
	{
		if (strs[i++])
			nb_not_null++;
	}
	return (nb_not_null == expected_len);
}

int check_suffix(char *path, char *suffix)
{
	int	len;
	int len_suffix;

	len_suffix = ft_strlen(suffix);
	len = ft_strlen(path);
	if (len < len_suffix
			|| ft_strncmp(path + len - len_suffix, suffix, len_suffix) != 0)
		return (1);
	return (0);
}


int parse_texture_line(t_data *data, char *path_texture, int direction)
{
	char *path;
	int	fd;

	if (data->textures[direction])
		return (puts("error 1"), 1);
	if (check_suffix(path_texture, ".xpm"))
		return (puts("error 2"), 1);
	fd = open(path_texture, O_RDONLY);
	if (fd < 0)
		return (puts("error 3"), 1);
	close(fd);
	path = ft_strdup(path_texture);
	if (!path)
		return (puts("error 4"), 1);
	data->textures[direction] = path;
	return (0);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}

int check_texture(t_data *data, int fd)
{
	char	*line;
	char	**strs;

	while (!check_empty(data->textures, 4))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		strs = ft_split_custom(line, " \f\t\n\r\v");
		free(line);
		if (ft_strslen(strs) == 0)
		{
			// free strs
			continue ;
		}
		if (ft_strslen(strs) != 2)
			return (1);
		if (!ft_strcmp(strs[0], "NO"))
		{
			if (parse_texture_line(data, strs[1], N))
				return (puts("side N"), 1);
		}
		else if (!ft_strcmp(strs[0], "SO"))
		{
			if (parse_texture_line(data, strs[1], S))
				return (puts("side S"), 1);
		}
		else if (!ft_strcmp(strs[0], "EA"))
		{
			if (parse_texture_line(data, strs[1], E))
				return (puts("side E"), 1);
		}
		else if (!ft_strcmp(strs[0], "WE"))
		{
			if (parse_texture_line(data, strs[1], W))
				return (puts("side W"), 1);
		}
		else
			return (1);
		puts("\n\ndata:");
		for (int a = 0; a < 4; a++)
			printf("%d: %s\n", a, data->textures[a]);
	}
	if (!check_empty(data->textures, 4))
		return (1);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break ;
	// 	puts(line);
	// 	free(line);
	// }
	return (0);
}

	// finish ny .cub


void init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
		data->textures[i++] = NULL;
}



//main parsing
int	parsing(t_data *data, char *path)
{
	int fd;

	init_data(data);
	if (check_suffix(path, ".cub")) //finish by .cub
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (check_texture(data, fd)) //using gnl
		return (1);
	if (check_floor_ceiling(data, fd)) //using gnl
	// 	return (1);
	// if (check_map(fd)) //using gnl
	// 	return (1);
	close(fd);


	return (0);
}
