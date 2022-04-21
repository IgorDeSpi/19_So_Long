/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:34:15 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/21 14:40:24 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		file = get_file(COIN, game->c_i);
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
	int		i;
	int		j;
	char	*str;
	int		c;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
	str = ft_itoa(game->count_move);
	c = create_trgb(1, 255, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 10, 0, c, "Moves : ");
	mlx_string_put(game->mlx, game->mlx_win, 100, 0, c, str);
	free(str);
}

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

static char	*get_file(char *start, int index)
{
	char	*file;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_itoa(index);
	tmp2 = ft_strjoin(start, tmp1);
	file = ft_strjoin(tmp2, ".xpm");
	free(tmp1);
	free(tmp2);
	return (file);
}

void	draw_enemy_block(t_game *game)
{
	int		width;
	int		height;
	void	*img;
	char	*file;

	if (game->enemy_exist)
	{
		file = get_file(ENEMY, game->enemy_xpm_index);
		img = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
		if (!img)
			got_error_map_not_found();
		width = BLOCK_SIZE * game->e_x;
		height = BLOCK_SIZE * game->e_y;
		mlx_put_image_to_window(game->mlx, game->mlx_win, img, width, height);
		mlx_destroy_image(game->mlx, img);
		free(file);
	}
}
