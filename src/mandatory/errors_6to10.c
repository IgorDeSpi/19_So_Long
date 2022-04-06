/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_6to10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:09:07 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/06 17:20:42 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	got_error_map_exit(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_EXIT\n", 1);
	exit(ERROR_MAP_EXIT);
}

void	got_error_map_coins(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_COINS\n", 1);
	exit(ERROR_MAP_COINS);
}

void	got_error_map_forbidden_item(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_FORBIDDEN_ITEM\n", 1);
	exit(ERROR_MAP_FORBIDDEN_ITEM);
}

void	got_error_map_not_ber_extension(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_MAP_NOT_BER_EXTENSION\n", 1);
	exit(ERROR_MAP_NOT_BER_EXTENSION);
}

void	got_error_game_is_null(void)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd("ERROR_GAME_IS_NULL\n", 1);
	exit(ERROR_GAME_IS_NULL);
}
