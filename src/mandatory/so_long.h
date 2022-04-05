/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:26:50 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/05 15:15:12 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./gnl/get_next_line.h"

//! IMG path
# define PLAYER "img/mario.xpm"
# define WALL "img/cloud.xpm"
# define COIN "img/coin.xpm"
# define BG "img/floor.xpm"
# define EXIT_OPEN "img/exit_open.xpm"
# define EXIT_CLOSED "img/exit_closed.xpm"

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
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		nbr_coins;
	void	*mlx;
	void	*mlx_win;
}				t_game;

#endif