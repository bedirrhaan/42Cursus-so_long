/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:16:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 17:24:30 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, ft_size_word(s, c, i));
		if (!(strs[j]))
			return (ft_free(strs, j));
		i += ft_size_word(s, c, i);
	}
	strs[j] = 0;
	return (strs);
}

char	**copy_two_dimensional_array(char **array)
{
	int		i;
	int		j;
	char	**copy_array;

	copy_array = (char **)malloc(sizeof(char *) * td_strlen(array) + 1);
	i = 0;
	j = 0;
	if (!copy_array)
		return (NULL);
	while (array[i])
	{
		j = 0;
		copy_array[i] = malloc(sizeof(char *) * ft_strlen(array[i]) + 1);
		if (!(copy_array[i]))
			return (ft_free(copy_array, i), NULL);
		while (array[i][j])
		{
			copy_array[i][j] = array[i][j];
			j++;
		}
		copy_array[i][j] = '\0';
		i++;
	}
	copy_array[i] = NULL;
	return (copy_array);
}
