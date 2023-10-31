/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:43:07 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/10/30 16:53:52 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct so_long
{
    char    **map;
    int     map_size;
}               so_game;

int     map_open(char *map_name, so_game *particles);
int     map_checker(so_game *particles);
int     map_name_checker(char *map_name);
int     wall_control(so_game *particles);
int     component_control(so_game *particles);
int 	start_game(char *map_name);
int		ft_strlen(char *str);
int     td_strlen(char **two_dimensional_array);
int	    ft_strchr(const char *s, int c);
char    **ft_split(char *str);


#endif