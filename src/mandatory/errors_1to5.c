/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:09:10 by ide-spir          #+#    #+#             */
/*   Updated: 2022/04/06 11:38:52 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	got_error_map_not_found(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_FOUND", 1);
	return (ERROR_MAP_NOT_FOUND);
}

void	got_error_map_not_valid(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_NOT_VALID", 1);
	return (ERROR_MAP_NOT_VALID);
}

void	got_error_map_width(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_WIDTH", 1);
	return (ERROR_MAP_WIDTH);
}

void	got_error_map_border(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_BORDER", 1);
	return (ERROR_MAP_BORDER);
}

void	got_error_map_player(void)
{
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("ERROR_MAP_PLAYER", 1);
	return (ERROR_MAP_PLAYER);
}
