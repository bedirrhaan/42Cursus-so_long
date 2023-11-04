/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:43:07 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/04 23:43:05 by bcopoglu         ###   ########.fr       */
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
    int     collectibles;

    // PATH FINDER
    char    **copy_map;
    int     player_x;
    int     player_y;
    int     player_e_x;
    int     player_e_y;
    
}               so_game;

//START
void 	start_game(char *map_name);

//MAP
int	    control(so_game *particles, char *map_name);
int     map_open(char *map_name, so_game *particles);
int     map_checker(so_game *particles);
int     map_name_checker(char *map_name);
int     wall_control(so_game *particles);
int     component_control(so_game *particles);

//UTILS
int     ft_strlen(const char *str);
int     td_strlen(char **two_dimensional_array);
int	    ft_strchr(const char *s, int c);
char    **ft_split(char const *s, char c);
char	**copy_two_dimensional_array(char **array);
void	ft_map_free(so_game *particles);

//PATH FINDER
int     path_finder(so_game *particles);
int     player_exit_control(so_game *particles);
void    recursive_p(so_game *map, int y, int x);
void	ft_copymap_free(so_game *particles);


#endif