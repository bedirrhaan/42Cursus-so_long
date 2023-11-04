/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/05 01:30:42 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <unistd.h>

int	start_game(char *map_name)
{
	so_game	particles;

	if (!(map_name_checker(map_name)))
		return (write (1, "Map Name Error\n", 16), 0);
	if (!(map_open(map_name, &particles)))
		return (write (1, "Map Open Error\n", 16), 0);
	if (!(control(&particles)))
		return (ft_map_free(&particles), 0);
	return (ft_map_free(&particles), 0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write (1, "Error\n", 5), 0);
	if (!(start_game(av[1])))
		return (0);
	return (0);
}
