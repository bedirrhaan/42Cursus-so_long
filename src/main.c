/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/05 23:20:37 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"
#include <unistd.h>

int	object_image_up(so_game *g)
{
	int	x;
	int	y;

	g->floor_s = mlx_xpm_file_to_image(g->mlx, "./textures/ground.xpm", &x, &y);
	g->coin_s = mlx_xpm_file_to_image(g->mlx, "./textures/egg.xpm", &x, &y);
	g->wall_s = mlx_xpm_file_to_image(g->mlx, "./textures/wood.xpm", &x, &y);
	g->player_s = mlx_xpm_file_to_image(g->mlx, "./textures/chick.xpm", &x, &y);
	g->exit_s = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &x, &y);
	if (g->floor_s == 0 || g->coin_s == 0 || g->wall_s == 0 || g->player_s == 0
		|| g->exit_s == 0)
		return (0);
	return (1);
}

void	object_put(char *str, so_game *game, int y)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '0')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == '1')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_s,
				x * 32, y * 32);
		else if (str[x] == 'C')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin_s,
				x * 32, y * 32);
		else if (str[x] == 'P')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_s,
				x * 32, y * 32);
		x++;
	}
}

int	player_movement(int keycode, so_game *g)
{
	int	x;
	int	y;

	x = g->player_x;
	y = g->player_y;
	if (keycode == KEY_ESC)
		game_exit(g);
	else if (keycode == KEY_W && g->map[g->player_y - 1][g->player_x] != '1')
		g->player_y--;
	else if (keycode == KEY_S && g->map[g->player_y + 1][g->player_x] != '1')
		g->player_y++;
	else if (keycode == KEY_A && g->map[g->player_y][g->player_x - 1] != '1')
		g->player_x--;
	else if (keycode == KEY_D && g->map[g->player_y][g->player_x + 1] != '1')
		g->player_x++;
	if (x != g->player_x || y != g->player_y)
	{
		player_object_update(g);
		g->another++;
		return (ft_putnbr(g->another), ft_putstr(". Number.\n"), 1);
	}
	return (1);
}

int	start_game(char *map_name)
{
	so_game	particles;

	particles.another = 0;
	if (!(map_name_checker(map_name)))
		return (write (1, "Map Name Error\n", 16), 0);
	if (!(map_open(map_name, &particles)))
		return (write (1, "Map Open Error\n", 16), 0);
	if (!(control(&particles)))
		return (ft_map_free(&particles), 0);

	particles.mlx = mlx_init();
	if (!particles.mlx)
		return (0);
	particles.mlx_win = mlx_new_window(particles.mlx, particles.map_w * 32, particles.map_h * 32, "AnimeGirl");
	if (!particles.mlx_win)
		return (free(particles.mlx), 0);
	if (object_image_up(&particles) == 0)
		return (0);

	mlx_key_hook(particles.mlx_win, player_movement, &particles);
	mlx_hook(particles.mlx_win, 17, 0L << 0, game_exit, &particles);
	mlx_loop_hook(particles.mlx, map_update, &particles);
	mlx_loop(particles.mlx);
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
