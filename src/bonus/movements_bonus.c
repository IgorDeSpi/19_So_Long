/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:41:41 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/21 10:49:26 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	can_move(t_game *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == W_UP)
		i = -1;
	if (direction == S_DOWN)
		i = 1;
	if (direction == A_LEFT)
		j = -1;
	if (direction == D_RIGHT)
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
		{
			ft_putstr_fd("GG\n", 1);
			close_game(game);
		}
	}
	game->map[game->p_y][game->p_x] = 'P';
	if (game->game)
	{
		game->count_move++;
		ft_putstr_fd("Moves : ", 1);
		ft_putnbr_fd(game->count_move, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
	}
}

int	can_move_enemy(t_game *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_UP)
		i = -1;
	if (direction == KEY_DOWN)
		i = 1;
	if (direction == KEY_LEFT)
		j = -1;
	if (direction == KEY_RIGHT)
		j = 1;
	if (game->map[game->e_y + i][game->e_x + j] == '1')
		return (0);
	if (game->map[game->e_y + i][game->e_x + j] == 'C')
		return (0);
	if (game->map[game->e_y + i][game->e_x + j] == 'E')
		return (0);
	return (1);
}

void	move_enemy(t_game *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_UP)
		i = -1;
	if (direction == KEY_DOWN)
		i = 1;
	if (direction == KEY_LEFT)
		j = -1;
	if (direction == KEY_RIGHT)
		j = 1;
	game->map[game->e_y][game->e_x] = '0';
	game->e_y += i;
	game->e_x += j;
}
