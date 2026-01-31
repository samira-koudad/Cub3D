/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:51:28 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/31 18:45:14 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_line(t_line *curr, bool free_str)
{
	t_line *next;

	while (curr)
	{
		next = curr->next;
		if (free_str)
			free(curr->str);
		free(curr);
		curr = next;
	}
}

int count_line(t_line *curr)
{
	int len;

	len = 0;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

char **map_table(t_line *curr)
{
	char **table;
	int size;
	int i ;
	int size_line;

	size = count_line(curr);

	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (!table)
		return (NULL);
	table[size] = NULL;
	i = 0;
	while (i < size)
	{
		size_line = ft_strlen(curr->str);
		if (size_line > 0 && curr->str[size_line - 1] == '\n')
			curr->str[size_line - 1] = '\0';
		table[i] = curr->str;
		curr = curr->next;
		i++;
	}
	return (table);
}

t_line *fill_line(char *line)
{
	t_line *current;

	current = malloc(sizeof(t_line));
	if (!current)
		return (NULL);
	current->next = NULL;
	current->str = line;
	return (current);
}

int	verify_map(char **table)
{
	int	i;
	int	j;

	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			if (table[i][j] == '0' || table[i][j] == '1' || table[i][j] == ' ' || table[i][j] == '\t'
			|| table[i][j] == '\r' || table[i][j] == '\v' || table[i][j] == 'N' || table[i][j] == 'S'
			|| table[i][j] == 'E' || table[i][j] == 'W')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int is_in(char *c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// check qu'on a 1 joueur (N/S/E/W) only et uniquement 0 / 1 / space
int check_map_content(char **map, t_data *data)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_in(map[i][j], "01NESW \f\t\r\v") == -1)
				return (1);
			if (is_in(map[i][j], "NESW") != -1)
			{
				data->player.spawn_orientation = is_in(map[i][j], "NESW");
				data->player.x = (float)j;
				data->player.y = (float)i;
				map[i][j] = '0';
				pos++;
			}
			else if (is_in(map[i][j], " \f\t\r\v"))
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	if (pos == 1)
		return (0);
	return (1);
}



int check_map(t_data *data, int fd)
{
	char *line;
	t_line *current_line;
	t_line *previous_line;

	data->beggin = NULL;
	previous_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_line = fill_line(line);
		if (!current_line)
			return (free_line(data->beggin, true), free(line), 1); // free la liste chainee
		if (!previous_line)
			data->beggin = current_line;
		if (previous_line)
			previous_line->next = current_line;
		previous_line = current_line;
	}
	data->map = map_table(data->beggin);
	if (!data->map)
		return (1); // free la liste chainée
	if (check_map_content(data->map, data))
		return (1); // free la liste chainée
	if (check_map_closed(data->map))
		return (1); // free la liste chainée
	return (0);
}
