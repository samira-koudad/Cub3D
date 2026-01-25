/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:21:42 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/25 16:02:53 by skoudad          ###   ########.fr       */
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

typedef enum e_direction{
	N,
	S,
	E,
	W,
} s_direction;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data {
	char	*textures[4];
	t_color	floor;
	t_color	ceiling;

} t_data ;

void	ft_str(char *str);
int		parsing(t_data *data, char *path);
int	ft_strslen(char **strs);
int check_floor_ceiling(t_data *data, int fd);
int	put_color(t_color *color, char *floorc);

#endif
