/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:26 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/05 15:14:13 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_file(char *map_file)
{
	char	*s;

	if (!map_file)
		return (0);
	s = ft_strrchr(map_file, '.');
	if (!s)
		return (0);
	if (ft_strlen(map_file) < 5)
		return (0);
	if (ft_strncmp(s, ".ber", 5))
		return (0);
	return (1);
}

int	check_map_border(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		if (i == 0 || i == game->height - 1)
		{
			while (++j < game->width)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
		}
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_map_width(t_game *game)
{
	int	i;

	i = -1;
	if (!game || !game->map)
		return (0);
	while (++i < game->height - 1)
	{
		if (ft_strlen(game->map[i]) - 1 != (size_t)game->width)
			return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game)
		got_error_game_is_null();
	if (!check_map_width(game))
		got_error_map_width();
	if (!check_map_border(game))
		got_error_map_border();
	if (!check_map_player(game))
		got_error_map_player();
	if (!check_map_exit(game))
		got_error_map_exit();
	if (!check_map_coins(game))
		return (0);
	if (!check_map_other_chars(game))
		got_error_map_forbidden_item();
	return (1);
}
