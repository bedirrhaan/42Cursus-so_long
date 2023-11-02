/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:43:07 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/02 14:06:00 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>

typedef struct so_long
{
    char    **map;
    int     map_size;
}               so_game;

//START
int 	start_game(char *map_name);

//MAP
int     map_open(char *map_name, so_game *particles);
int     map_checker(so_game *particles);
int     map_name_checker(char *map_name);
int     wall_control(so_game *particles);
int     component_control(so_game *particles);

//UTILS
size_t  ft_strlen(const char *str);
size_t  td_strlen(char **two_dimensional_array);
int	    ft_strchr(const char *s, int c);
char    **ft_split(char const *s, char c);

#endif