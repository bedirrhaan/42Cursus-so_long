/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/04 23:46:44 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <unistd.h>

void	start_game(char *map_name)
{
	so_game	particles;

	if (!(control(&particles, map_name)))
		ft_map_free(&particles);
	ft_map_free(&particles);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write (1, "Error\n", 5), 0);
	start_game(av[1]);
	return (0);
}
