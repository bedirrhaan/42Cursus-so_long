/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:58:12 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/07 17:07:13 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../headers/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

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

int	map_fill(t_game *particles, int fd)
{
	char	*line;
	char	*swap;

	line = get_next_line(fd);
	if (!line || fd < 0)
		return (0);
	particles->map_swap = ft_strdup(line);
	free(line);
	if (!particles->map_swap)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break ;
		swap = ft_strjoin(particles->map_swap, line);
		free(line);
		if (!swap || ft_strlen(particles->map_swap) < 4)
			return (free(particles->map_swap), 0);
		free(particles->map_swap);
		particles->map_swap = swap;
	}
	return (1);
}

int	calculate_map(t_game *particles)
{
	particles->map = ft_split(particles->map_swap, '\n');
	if (!particles->map)
		return (free(particles->map_swap), 0);
	free(particles->map_swap);
	return (1);
}
