/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:41:41 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/16 14:47:15 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_UP || direction == W_UP)
		i = -1;
	if (direction == KEY_DOWN || direction == S_DOWN)
		i = 1;
	if (direction == KEY_LEFT || direction == A_LEFT)
		j = -1;
	if (direction == KEY_RIGHT || direction == D_RIGHT)
		j = 1;
	if (game->map[game->p_y + i][game->p_x + j] == '1')
		return (0);
	if (game->map[game->p_y + i][game->p_x + j] == 'E')
		if (game->nbr_coins)
			return (0);
	game->map[game->p_y][game->p_x] = '0';
	game->p_y += i;
	game->p_x += j;
	return (1);
}

void	move_player(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'C')
		game->nbr_coins--;
	if (game->map[game->p_y][game->p_x] == 'E')
	{
		if (game->nbr_coins == 0)
			close_game(game);
	}
	game->map[game->p_y][game->p_x] = 'P';
	if (game->game)
	{
		game->count_move++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(game->count_move, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
	}
}
