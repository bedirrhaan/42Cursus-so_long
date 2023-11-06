/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:58:12 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 18:18:17 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../headers/so_long.h"
#include "../get_next_line/get_next_line.h"

int	map_open(char *map_name, t_game *particles)
{
	int		fd;
	char	*line;
	char	*swap;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	particles->map_swap = ft_strdup(line);
	free(line);
	if (!particles->map_swap)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break;
		if (ft_strlen(line) < 4)
			return (free(particles->map_swap), 0);
		swap = ft_strjoin(particles->map_swap, line);
		free(line);
		if (!swap)
			return (free(particles->map_swap), 0);
		free(particles->map_swap),
		particles->map_swap = swap;
	}
	return (1);
}

int		calculate_map(t_game *particles)
{
	particles->map = ft_split(particles->map_swap, '\n');
	if (!particles->map)
		return (free(particles->map_swap), 0);
	free(particles->map_swap);
	return (1);
}