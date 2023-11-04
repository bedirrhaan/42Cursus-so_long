/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:31 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/04 23:42:52 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../headers/so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	td_strlen(char **two_dimensional_array)
{
	int	i;

	i = 0;
	while (two_dimensional_array[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

void	ft_map_free(so_game *particles)
{
	int		i;

	i = 0;
	if (particles->map)
	{
		while (particles->map[i])
		{
			free(particles->map[i]);
			i++;
		}
		free(particles->map);
	}
}

void	ft_copymap_free(so_game *particles)
{
	int		i;

	i = 0;
	if (particles->copy_map)
	{
		while (particles->copy_map[i])
		{
			free(particles->copy_map[i]);
			i++;
		}
		free(particles->copy_map);
	}
}