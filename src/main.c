/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/02 14:01:07 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mlx.h"
#include "../headers/so_long.h"
#include <stdlib.h>
#include <unistd.h>

int	start_game(char *map_name)
{
	so_game	particles;
	int		i;

	if (!(map_name_checker(map_name)))
		write (1, "Map Name Error\n", 16);
	if (!(map_open(map_name, &particles)))
		write (1, "Map Open Error\n", 16);
	if (!(map_checker(&particles)))
		write (1, "Map Error\n", 11);
	if (!(wall_control(&particles)))
		write (1, "Map Wall Error\n", 16);
	if (!(component_control(&particles)))
		write (1, "Map Component Error\n", 21);
	i = 0;
	if (particles.map)
	{
		while (particles.map[i])
		{
			free(particles.map[i]);
			i++;
		}
		free(particles.map);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write (1, "Error\n", 5), 0);
	if (!(start_game(av[1])))
		return (0);
	return (0);
}
