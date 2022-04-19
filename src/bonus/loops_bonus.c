/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:40:21 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/19 14:12:39 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_coin(int frames, t_game *game)
{
	if (frames % 500 == 0)
	{
		if (game->c_i_direction)
		{
			if (game->c_i == 6)
			{
				game->c_i--;
				game->c_i_direction = 0;
			}
			else
				game->c_i++;
		}
		else
		{
			if (game->c_i == 0)
			{
				game->c_i++;
				game->c_i_direction = 1;
			}
			else
				game->c_i--;
		}
		draw_map(game);
		draw_enemy_block(game);
	}
}

void	animate_enemy(int frames, t_game *game)
{
	if (game->enemy_exist && frames % 1000 == 0)
	{
		if (game->enemy_xpm_index_direction)
		{
			if (game->enemy_xpm_index == 5)
			{
				game->enemy_xpm_index--;
				game->enemy_xpm_index_direction = 0;
			}
			else
				game->enemy_xpm_index++;
		}
		else
		{
			if (game->enemy_xpm_index == 0)
			{
				game->enemy_xpm_index++;
				game->enemy_xpm_index_direction = 1;
			}
			else
				game->enemy_xpm_index--;
		}
		draw_enemy_block(game);
	}
}

int	loops(t_game *game)
{
	static int	frames = 0;
	static int	rand = 1;

	animate_coin(frames, game);
	if (game->game)
	{
		animate_enemy(frames, game);
		if (game->enemy_exist && game->game && frames % 1000 == 0)
		{
			if (rand % 5 == 0)
				move_enemy_hook(game, KEY_UP);
			if (rand % 5 == 1)
				move_enemy_hook(game, KEY_DOWN);
			if (rand % 5 == 2)
				move_enemy_hook(game, KEY_LEFT);
			if (rand % 5 == 3)
				move_enemy_hook(game, KEY_RIGHT);
			if (game->e_x == game->p_x && game->e_y == game->p_y)
				close_game(game);
		}
		frames++;
		rand *= 13;
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
