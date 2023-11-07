/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:03 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/07 00:38:02 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	object_image_up(t_game *g)
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
	{
		game_exit(g);
		write(1, "False XPM Extension", 19);
		return (0);
	}
	return (1);
}

void	object_put(char *str, t_game *game, int y)
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

int	player_movement(int keycode, t_game *g)
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
