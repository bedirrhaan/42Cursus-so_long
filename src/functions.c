/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:31 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/10/30 19:21:47 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
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

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[i] == '\n')
		i += 1;
	while (str[i])
	{
		j = 0;
		split[k] = (char *)malloc(sizeof(char) * 4096);
		if (!split)
			return (NULL);
		while (str[i] != '\n' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == '\n')
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = NULL;
	return (split);
}
