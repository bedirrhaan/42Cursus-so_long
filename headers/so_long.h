/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:43:07 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/05 23:17:30 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct so_long
{
    char    **map;
    int     map_size;
    int     collectibles;
    int     map_h;
    int     map_w;
    int     another;
    int     collectibles_copy;


    // PATH FINDER
    char    **copy_map;
    int     player_x;
    int     player_y;
    int     player_e_x;
    int     player_e_y;
    void    *mlx;
    void    *mlx_win;

    //IMAGES
    void    *floor_s;
    void    *coin_s;
    void    *wall_s;
    void    *player_s;
    void    *exit_s;


}               so_game;

//START
int 	start_game(char *map_name);

//MAP
int	    control(so_game *particles);
int     map_open(char *map_name, so_game *particles);
int     map_checker(so_game *particles);
int     map_name_checker(char *map_name);
int     wall_control(so_game *particles);
int     component_control(so_game *particles);
int	    map_update(so_game *game);
void	object_put(char *str, so_game *game, int y);
int 	game_exit(so_game *game);
void	player_object_update(so_game *game);
void    ft_putnbr(int nbr);
void    ft_putstr(char *str);

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
