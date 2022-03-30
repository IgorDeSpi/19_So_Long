/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:06:05 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/16 11:09:36 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

int		ft_printf(const char *str, ...);

void	if_char(t_print *arg_count);
void	if_str(t_print *arg_count);
void	if_ptr(t_print *arg_count);
void	if_hex(t_print *arg_count, char c);
void	if_int(t_print *arg_count);
void	if_u_int(t_print *arg_count);

#endif
