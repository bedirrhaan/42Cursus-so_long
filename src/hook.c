/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:58:10 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/05 23:20:49 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/mlx.h"

int	map_update(so_game *game)
{
	int	y;

	y = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (game->map[y])
	{
		object_put(game->map[y], game, y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_s,
		game->player_x * 32, game->player_y * 32);
	return (1);
}

int	game_exit(so_game *game)
{
	ft_map_free(game);
	mlx_destroy_image(game->mlx, game->coin_s);
	mlx_destroy_image(game->mlx, game->player_s);
	mlx_destroy_image(game->mlx, game->wall_s);
	mlx_destroy_image(game->mlx, game->exit_s);
	mlx_destroy_image(game->mlx, game->floor_s);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	player_object_update(so_game *game)
{
	if (game->collectibles == 0 && game->map[game->player_y][game->player_x] == 'E')
		game_exit(game);
	else if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
	}
}
