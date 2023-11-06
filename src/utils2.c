/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:12:26 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 17:25:59 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_map_free(t_game *particles)
{
	int		i;

	i = 0;
	while (particles->map[i])
	{
		free(particles->map[i]);
		i++;
	}
	free(particles->map);
}

void	ft_copymap_free(t_game *particles)
{
	int		i;

	i = 0;
	while (particles->copy_map[i])
	{
		free(particles->copy_map[i]);
		i++;
	}
	free(particles->copy_map);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	write (1, &"0123456789"[nbr % 10], 1);
}
