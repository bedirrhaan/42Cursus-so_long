/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:38:27 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 18:08:40 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../headers/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	map_name_checker(char *map_name)
{
	int		size;

	size = ft_strlen(map_name);
	if (size < 4)
		return (0);
	size -= 4;
	while (map_name[size])
	{
		if (!(ft_strchr(".ber", map_name[size])))
			return (0);
		size++;
	}
	return (1);
}

int	map_checker(t_game *particles)
{
	int	i;

	i = 0;
	particles->map_h = td_strlen(particles->map);
	particles->map_w = ft_strlen(particles->map[0]);
	while (particles->map[i + 2])
	{
		if (ft_strlen(particles->map[i]) != ft_strlen(particles->map[i + 1]))
			return (0);
		i++;
	}
	if (ft_strlen(particles->map[0]) == td_strlen(particles->map))
		return (0);
	return (1);
}

int	wall_control(t_game *particles)
{
	int		i;
	int		j;
	int		size;
	int		len;

	size = td_strlen(particles->map) - 1;
	j = 0;
	while (particles->map[0][j])
	{
		if (particles->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (particles->map[size][j])
	{
		if (particles->map[size][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (particles->map[i][0] && i < size)
	{
		len = ft_strlen(particles->map[i]) - 1;
		if (particles->map[i][0] != '1')
			return (0);
		if (particles->map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	component_control(t_game *particles)
{
	int	i;
	int	j;
	int	exit;
	int	player_start;

	i = 0;
	exit = 0;
	player_start = 0;
	particles->collectibles = 0;
	while (particles->map[i])
	{
		j = 0;
		while (particles->map[i][j])
		{
			if (particles->map[i][j] == 'C')
				particles->collectibles++;
			if (particles->map[i][j] == 'E')
			{
				particles->player_e_x = i;
				particles->player_e_y = j;
				exit++;
			}
			if (particles->map[i][j] == 'P')
			{
				player_start++;
				particles->player_y = i;
				particles->player_x = j;
			}
			if (particles->map[i][j] != '0' && particles->map[i][j] != '1' &&
			particles->map[i][j] != 'P' &&
			particles->map[i][j] != 'C' && particles->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	if (exit == 1 && player_start == 1 && particles->collectibles != 0)
		return (1);
	return (0);
}
