/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:34:15 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/07 11:24:38 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img_block(t_game *game, char c, int x, int y)
{
	int		width;
	int		height;
	void	*img;
	char	*file;

	if (c == '0')
		file = ft_strdup(BG);
	if (c == 'P')
		file = ft_strdup(PLAYER);
	if (c == '1')
		file = ft_strdup(WALL);
	if (c == 'C')
		file = ft_strdup(COIN);
	if (c == 'E' && game->nbr_coins != 0)
		file = ft_strdup(EXIT_CLOSED);
	if (c == 'E' && game->nbr_coins == 0)
		file = ft_strdup(EXIT_OPEN);
	img = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
	width = BLOCK_SIZE * x;
	height = BLOCK_SIZE * y;
	if (!img)
		got_error_map_not_found();
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, width, height);
	mlx_destroy_image(game->mlx, img);
	free(file);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
}

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
