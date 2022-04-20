/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:15:47 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/20 15:18:00 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_height(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}

int	free_game(t_game **game)
{
	int	i;

	i = -1;
	if (!game || !(*game))
		return (0);
	while (++i < (*game)->height)
		free((*game)->map[i]);
	free((*game)->map);
	free(*game);
	*game = NULL;
	return (0);
}

int	init_map(char *map_path, t_game *game)
{
	int	height;
	int	fd;
	int	i;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
			got_error_map_not_found();
	height = count_height(fd);
	if (height == 0)
		got_error_map_not_valid();
	game->map = malloc(sizeof(char *) * (height));
	close(fd);
	i = -1;
	fd = open(map_path, O_RDONLY);
	while (++i < height && game->map)
		game->map[i] = get_next_line(fd);
	close(fd);
	game->height = height;
	if (game->map)
		game->width = ft_strlen(game->map[i - 1]);
	if (!game->map || !check_map(game))
		return (free_game(&game));
	return (1);
}

t_game	*init_game(char *map_path)
{
	t_game	*game;

	if (!check_map_file(map_path))
		got_error_map_not_ber_extension();
	game = malloc(sizeof(t_game));
	if (!game)
		got_error_game_is_null();
	game->count_move = 0;
	game->game = 1;
	if (!init_map(map_path, game))
		game = NULL;
	return (game);
}
