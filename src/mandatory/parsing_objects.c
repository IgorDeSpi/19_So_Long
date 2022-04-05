/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:49:08 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/05 16:12:20 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_player(t_game *game)
{
	int	nbr_player;
	int	i;
	int	j;

	nbr_player = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				nbr_player++;
				game->p_x = j;
				game->p_y = i;
			}
		}
	}
	if (nbr_player == 1)
		return (1);
	else
		return (0);
}

int	check_map_exit(t_game *game)
{
	int	nbr_exit;
	int	i;
	int	j;

	nbr_exit = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'E')
				nbr_exit++;
		}
	}
	if (nbr_exit >= 1)
		return (1);
	else
		return (0);
}

int	check_map_coins(t_game *game)
{
	int	nbr_coins;
	int	i;
	int	j;

	nbr_coins = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				nbr_coins++;
		}
	}
	game->nbr_coins = nbr_coins;
	if (nbr_coins > 0)
		return (1);
	else
		return (0);
}

int	check_map_other_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (!ft_strchr("EPC01", game->map[i][j]))
				return (0);
		}
	}
	return (1);
}
