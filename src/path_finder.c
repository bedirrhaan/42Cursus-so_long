/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:14:05 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/05 00:58:45 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int path_finder(so_game *particles)
{
    particles->copy_map = copy_two_dimensional_array(particles->map);
    recursive_p(particles, particles->player_y, particles->player_x);
    if (particles->collectibles != 0)
        return (ft_copymap_free(particles), 0);
    if (!(player_exit_control(particles)))
        return (ft_copymap_free(particles), 0);
    return (ft_copymap_free(particles), 1);
}

int player_exit_control(so_game *particles)
{
    if (particles->copy_map[particles->player_e_x + 1][particles->player_e_y] != 'P')
        return (0);
    if (particles->copy_map[particles->player_e_x - 1][particles->player_e_y] != 'P')
        return (0);
    if (particles->copy_map[particles->player_e_x][particles->player_e_y + 1] != 'P')
        return (0);
    if (particles->copy_map[particles->player_e_x][particles->player_e_y - 1] != 'P')
        return (0);
    return (1);
}

void recursive_p(so_game *map, int y, int x)
{
    if (map->copy_map[y][x + 1] == '0' || map->copy_map[y][x + 1] == 'C')
    {
        if (map->copy_map[y][x + 1] == 'C')
            map->collectibles--;
        map->copy_map[y][x + 1] = 'P';
        recursive_p(map, y, x + 1);
    }
    if (map->copy_map[y][x - 1] == '0' || map->copy_map[y][x - 1] == 'C')
    {   
        if (map->copy_map[y][x - 1] == 'C')
            map->collectibles--;
        map->copy_map[y][x - 1] = 'P';
        recursive_p(map, y, x - 1);
    }
    if (map->copy_map[y + 1][x] == '0' || map->copy_map[y + 1][x] == 'C')
    {
        if (map->copy_map[y + 1][x] == 'C')
            map->collectibles--;
        map->copy_map[y + 1][x] = 'P';
        recursive_p(map, y + 1, x);
    }
    if (map->copy_map[y - 1][x] == '0' || map->copy_map[y - 1][x] == 'C')
    {
        if (map->copy_map[y - 1][x] == 'C')
            map->collectibles--;
        map->copy_map[y - 1][x] = 'P';
        recursive_p(map, y - 1, x);
    }
}