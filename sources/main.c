/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:06:21 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/22 20:49:56 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_str(char *str)
{
	while (*str)
		write(2, str++, 1);
}



int main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		return (ft_str("Erro : Wrong number of arguments \n"), 1);
	if (parsing(&data, av[1]))
		return (ft_str("Error : wrong map, choose a valid one \n"), 1);
	return (0);
}

