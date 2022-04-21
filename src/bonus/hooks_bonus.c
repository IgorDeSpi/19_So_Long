/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:39:38 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/21 14:49:51 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_hook(t_game *game, int keycode)
{
	if (!can_move(game, keycode))
		return (0);
	move_player(game);
	return (1);
}

int	hooks(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if ((keycode == S_DOWN) && game->game)
		move_hook(game, keycode);
	if ((keycode == W_UP) && game->game)
		move_hook(game, keycode);
	if ((keycode == A_LEFT) && game->game)
		move_hook(game, keycode);
	if ((keycode == D_RIGHT) && game->game)
		move_hook(game, keycode);
	return (0);
}

int	destroy_hook(t_game *game)
{
	close_game(game);
	return (0);
}

int	move_enemy_hook(t_game *game, int keycode)
{
	if (!can_move_enemy(game, keycode))
		return (0);
	move_enemy(game, keycode);
	return (1);
}
