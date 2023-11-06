/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 17:59:07 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"
#include <unistd.h>
#include <stdlib.h>

int	control(t_game *particles)
{
	if (!(map_checker(particles)))
		return (write (1, "Map Error\n", 11), 0);
	if (!(wall_control(particles)))
		return (write (1, "Map Wall Error\n", 16), 0);
	if (!(component_control(particles)))
		return (write (1, "Map Component Error\n", 21), 0);
	if (!(path_finder(particles)))
		return (write (1, "Player cannot reach exit\n", 26), 0);
	return (1);
}

int	mlx_main(t_game *particles)
{
	particles->mlx = mlx_init();
	if (!particles->mlx)
		return (0);
	if (object_image_up(particles) == 0)
		return (0);
	else
	{
		particles->mlx_win = mlx_new_window(particles->mlx,
				particles->map_w * 32, particles->map_h * 32, "AnimeGirl");
		if (!particles->mlx_win)
			return (free(particles->mlx), 0);
		mlx_key_hook(particles->mlx_win, player_movement, particles);
		mlx_hook(particles->mlx_win, 17, 0, game_exit, particles);
		mlx_loop_hook(particles->mlx, map_update, particles);
		mlx_loop(particles->mlx);
	}
	return (1);
}

int	start_game(char *map_name)
{
	t_game	particles;

	particles.another = 0;
	if (!(map_name_checker(map_name)))
		return (write (1, "Map Name Error\n", 16), 0);
	if (!(map_open(map_name, &particles)))
		return (write (1, "Map Open Error\n", 16), 0);
	if (!(calculate_map(&particles)))
		return (write (1, "Map Create Error\n", 18), 0);
	if (!(control(&particles)))
		return (ft_map_free(&particles), 0);
	if (!(mlx_main(&particles)))
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
