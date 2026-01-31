/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:21:42 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/31 18:30:31 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"

// # include <mlx.h>
// # include <mlx_int.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
// S in NESW
// return 2
typedef enum e_direction{
	N,
	E,
	S,
	W,
} s_direction;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	float x;
	float y;
	float orientation;
	int spawn_orientation;
}	t_player;

typedef struct s_line {
	char	*str;
	struct s_line *next;

} t_line ;

typedef struct s_data {
	char	*textures[4];
	t_color	floor;
	t_color	ceiling;
	char **map;
	t_player player;
	t_line *beggin;

} t_data ;


void	ft_str(char *str);
int		parsing(t_data *data, char *path);
int	ft_strslen(char **strs);
int	put_color(t_color *color, char *floorc);
int check_map(t_data *data, int fd);
char **map_table(t_line *curr);

#endif
