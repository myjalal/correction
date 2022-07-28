/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:15:37 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 15:14:16 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# define WIN_W 60
# define WIN_H 60

// Estructuras
typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

// Imagen del map
typedef struct s_img_map {
	void		*id;
	t_vector	size;
}	t_img_map;

typedef struct s_sprite {
	void		*id;
	t_vector	size;
	char		*bits;
	int			bpp;
	int			sz_line;
	int			endian;
}	t_sprite;

typedef struct s_game {
	void		*mlx;
	void		*wnd;
	t_vector	wnd_sz;	
	t_vector	map_size;
	t_img_map	edge_up;
	t_img_map	centro;
	t_img_map	edge_up_dr;
	t_img_map	edge_up_iz;
	t_img_map	edge_dr;
	t_img_map	edge_iz;
	t_img_map	edge_bottom;
	t_img_map	rock;
	t_img_map	coin;
	t_img_map	ensayo;
	t_img_map	exit;
	t_sprite	player;
	t_vector	p_position;
	t_vector	e_position;
	int			colle;
	int			control_exit;
	int			moves;
	char		**map;
}	t_game;

//Map functions
t_game		init_map(char *map);
int			open_map(char *map);
void		parse_map(int fd, t_game *game);
char		*get_next_line(int fd);
int			check_map(t_game *game);
int			valid_wall(char **str, int last);
int			valid_wall_inter(char **str, int last);
int			get_map_size_y(int fd);
int			ft_strchrx(char *str, char c);
int			valid_collec(t_game *game);
int			valid_point_p(t_game *game);
int			valid_point_e(t_game *game);

// start game
void		game_init(t_game *game);
void		new_window(t_game *game, char *msg);
void		xpm_image(t_game *game);
void		render_start(t_game *game);
int			key_hook(int key, t_game *game);
int			control_player_x(t_game *game, int x);
int			control_player_y(t_game *game, int y);

// render
int			render_map_x(t_game *game);
void		render_map_y(t_game *game, int y);
void		render_sprites(t_game *game);
void		render_muro_inter(t_game *game);
void		render_coin(t_game *game);
void		string_put(t_game *game);
void		count_moves(t_game *game);

// Misc
void		error(char *s);
#endif
