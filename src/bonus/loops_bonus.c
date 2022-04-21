/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:40:21 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/21 14:49:58 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_coin(int frames, t_game *game)
{
	if (frames % 500 == 0)
	{
		if (game->c_i_direction)
		{
			if (game->c_i == 7)
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
			if (game->enemy_xpm_index == 3)
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
			check_rand(game, rand % 5);
			if (game->e_x == game->p_x && game->e_y == game->p_y)
			{
				ft_putstr_fd("GAME OVER\n", 1);
				close_game(game);
			}
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

void	check_rand(t_game *game, int rand)
{
	if (rand == 0)
		move_enemy_hook(game, KEY_UP);
	if (rand == 1)
		move_enemy_hook(game, KEY_DOWN);
	if (rand == 2)
		move_enemy_hook(game, KEY_LEFT);
	if (rand == 3)
		move_enemy_hook(game, KEY_RIGHT);
}
