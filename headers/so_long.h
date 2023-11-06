/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:43:07 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 18:08:48 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct so_long
{
	char	**map;
	char	*map_swap;
	int		map_size;
	int		collectibles;
	int		map_h;
	int		map_w;
	int		another;
	int		collectibles_copy;
	char	**copy_map;
	int		player_x;
	int		player_y;
	int		player_e_x;
	int		player_e_y;
	void	*mlx;
	void	*mlx_win;
	void	*floor_s;
	void	*coin_s;
	void	*wall_s;
	void	*player_s;
	void	*exit_s;

}			t_game;

//START
int		start_game(char *map_name);
int		player_movement(int keycode, t_game *g);
int		object_image_up(t_game *g);

//MAP
int		control(t_game *particles);
int		map_open(char *map_name, t_game *particles);
int		map_checker(t_game *particles);
int		map_name_checker(char *map_name);
int		wall_control(t_game *particles);
int		component_control(t_game *particles);
int		map_update(t_game *game);
void	object_put(char *str, t_game *game, int y);
int		game_exit(t_game *game);
void	player_object_update(t_game *game);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
int		calculate_map(t_game *particles);
int		mlx_main(t_game *particles);

//UTILS
int		ft_strlen(const char *str);
int		td_strlen(char **two_dimensional_array);
int		ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	**copy_two_dimensional_array(char **array);
void	ft_map_free(t_game *particles);

//SPLIT UTILS
int		ft_count_word(char const *s, char c);
int		ft_size_word(char const *s, char c, int i);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_free(char **strs, int j);


//PATH FINDER
int		path_finder(t_game *particles);
int		player_exit_control(t_game *particles);
void	recursive_p(t_game *map, int y, int x);
void	ft_copymap_free(t_game *particles);

#endif
