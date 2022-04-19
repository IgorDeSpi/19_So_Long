/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1to5_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:09:10 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/19 13:30:59 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	got_error_map_not_found(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_NOT_FOUND\n", 1);
	exit(ERROR_MAP_NOT_FOUND);
}

void	got_error_map_not_valid(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_NOT_VALID\n", 1);
	exit(ERROR_MAP_NOT_VALID);
}

void	got_error_map_width(void)
{
	ft_putstr_fd("Error :", 1);
	ft_putstr_fd("ERROR_MAP_WIDTH\n", 1);
	exit(ERROR_MAP_WIDTH);
}

void	got_error_map_border(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_BORDER\n", 1);
	exit(ERROR_MAP_BORDER);
}

void	got_error_map_player(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_PLAYER\n", 1);
	exit(ERROR_MAP_PLAYER);
}
