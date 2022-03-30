/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:35:23 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/16 11:54:14 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (!arg_count)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

void	print_check(const char c, t_print *arg_count)
{
	if (c == 'c')
		if_char(arg_count);
	else if (c == 's')
		if_str(arg_count);
	else if (c == 'p')
		if_ptr(arg_count);
	else if (c == 'i' || c == 'd')
		if_int(arg_count);
	else if (c == 'u')
		if_u_int(arg_count);
	else if (c == 'x' || c == 'X')
		if_hex(arg_count, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
	else if (c != '\0')
	{
		write(1, &c, 1);
		arg_count->counter++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_print	*arg_count;
	int		print_complete;
	int		i;

	i = 0;
	arg_count = start();
	print_complete = 0;
	va_start(arg_count->args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			print_check(str[++i], arg_count);
		else
		{
			ft_putchar_fd(str[i], 1);
			arg_count->counter++;
		}
		if (str[i] != '\0')
			i++;
	}
	print_complete = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (print_complete);
}
