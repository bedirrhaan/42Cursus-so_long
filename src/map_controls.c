/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:38:27 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/10/30 20:19:04 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	char	map_split[1000];

	fd = open(map_name, O_RDONLY);
	read(fd, map_split, 1000);
	particles->map = ft_split(map_split);
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
	int	collectibles;
	int	exit;
	int	player_start;

	i = 0;
	collectibles = 0;
	exit = 0;
	player_start = 0;
	while (particles->map[i])
	{
		j = 0;
		while (particles->map[i][j])
		{
			if (particles->map[i][j] == 'C')
				collectibles++;
			if (particles->map[i][j] == 'E')
				exit++;
			if (particles->map[i][j] == 'P')
				player_start++;
			if (particles->map[i][j] != '0' && particles->map[i][j] != '1' && particles->map[i][j] != 'P' && particles->map[i][j] != 'C' && particles->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	if (exit == 1 && player_start == 1)
		return (1);
	return (0);
}
