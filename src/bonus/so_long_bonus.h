/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:26:50 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/21 10:21:23 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./gnl/get_next_line_bonus.h"
# define BLOCK_SIZE 32
# define BUFFER_SIZE 1024

//! IMG path
# define PLAYER "img/mario.xpm"
# define WALL "img/wall.xpm"
# define COIN "img/coin-"
# define BG "img/background.xpm"
# define EXIT_OPEN "img/exit_open.xpm"
# define EXIT_CLOSED "img/exit_closed.xpm"
# define ENEMY "img/bowser-"

//! Event keys codes
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define W_UP 13
# define S_DOWN 1
# define A_LEFT 0
# define D_RIGHT 2
# define KEY_ESC 53

//! Errors
# define ERROR_MAP_NOT_FOUND 1
# define ERROR_MAP_NOT_VALID 2
# define ERROR_MAP_WIDTH 3
# define ERROR_MAP_BORDER 4
# define ERROR_MAP_PLAYER 5
# define ERROR_MAP_EXIT 6
# define ERROR_MAP_COINS 7
# define ERROR_MAP_FORBIDDEN_ITEM 8
# define ERROR_MAP_NOT_BER_EXTENSION 9
# define ERROR_GAME_IS_NULL 10

typedef struct s_game
{
	char	**map;
	int		game;
	int		c_i;
	int		c_i_direction;
	int		enemy_xpm_index;
	int		enemy_xpm_index_direction;
	int		enemy_exist;
	int		e_x;
	int		e_y;
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		nbr_coins;
	void	*mlx;
	void	*mlx_win;
}				t_game;

//! parsing_objects.c
int			check_map_player(t_game *game);
int			check_map_exit(t_game *game);
int			check_map_coins(t_game *game);
int			check_map_other_chars(t_game *game);

//! parsing_struct.c
int			check_map_file(char *map_file);
int			check_map_border(t_game *game);
int			check_map_width(t_game *game);
int			check_map(t_game *game);

//! errors_1to5.c
void		got_error_map_not_found(void);
void		got_error_map_not_valid(void);
void		got_error_map_width(void);
void		got_error_map_border(void);
void		got_error_map_player(void);

//! errors_6to10.c
void		got_error_map_exit(void);
void		got_error_map_coins(void);
void		got_error_map_forbidden_item(void);
void		got_error_map_not_ber_extension(void);
void		got_error_game_is_null(void);

//! init.c
int			count_height(int fd);
int			free_game(t_game **game);
int			init_map(char *map_path, t_game *game);
t_game		*init_game(char *map_path);
void		init_enemy(t_game *game);

//! movements.c
int			can_move(t_game *game, int direction);
void		move_player(t_game *game);
int			can_move_enemy(t_game *game, int direction);
void		move_enemy(t_game *game, int direction);

//! hooks.c
int			move_hook(t_game *game, int keycode);
int			hooks(int keycode, t_game *game);
int			destroy_hook(t_game *game);
int			move_enemy_hook(t_game *game, int keycode);

//! draw_map.c
void		draw_img_block(t_game *game, char c, int x, int y);
void		draw_map(t_game *game);
void		close_game(t_game *game);
static char	*get_file(char *start, int index);
void		draw_enemy_block(t_game *game);

//! loops_bonus.c
void		animate_coin(int frames, t_game *game);
void		animate_enemy(int frames, t_game *game);
int			loops(t_game *game);
int			create_trgb(int t, int r, int g, int b);

#endif