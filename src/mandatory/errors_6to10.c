/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_6to10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:09:07 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/06 13:37:08 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	got_error_map_exit(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_EXIT", 1);
	return (ERROR_MAP_EXIT);
}

void	got_error_map_coins(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_COINS", 1);
	return (ERROR_MAP_COINS);
}

void	got_error_map_forbidden_item(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_FORBIDDEN_ITEM", 1);
	return (ERROR_MAP_FORBIDDEN_ITEM);
}

void	got_error_map_not_ber_extension(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_BER_EXTENSION", 1);
	return (ERROR_MAP_NOT_BER_EXTENSION);
}

void	got_error_game_is_null(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_GAME_IS_NULL", 1);
	return (ERROR_GAME_IS_NULL);
}
