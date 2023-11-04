/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:38:27 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/04 18:37:21 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../headers/so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	control(so_game *particles, char *map_name)
{
	if (!(map_name_checker(map_name)))
		return (write (1, "Map Name Error\n", 16), 0);
	if (!(map_open(map_name, particles)))
		return (write (1, "Map Open Error\n", 16), 0);
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

int	map_name_checker(char *map_name)
{
	int		size;

	size = ft_strlen(map_name);
	if (size <= 4)
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

int	map_open(char *map_name, so_game *particles)
{
	int		fd;
	char	map_split[10000];

	fd = open(map_name, O_RDONLY);
	read(fd, map_split, 10000);
	particles->map = ft_split(map_split, '\n');
	if (!(particles->map))
	{
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	map_checker(so_game *particles)
{
	int	i;

	i = 0;
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

int	wall_control(so_game *particles)
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

int	component_control(so_game *particles)
{
	int	i;
	int	j;
	int	exit;
	int	player_start;

	i = 0;
	particles->collectibles = 0;
	exit = 0;
	player_start = 0;
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
				particles->player_x = i;
				particles->player_y = j;
			}
			if (particles->map[i][j] != '0' && particles->map[i][j] != '1' &&
			 particles->map[i][j] != 'P' &&
			 particles->map[i][j] != 'C' && particles->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	if (exit == 1 && player_start == 1)
		return (1);
	return (0);
}
