/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_ptr_str_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:14:47 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/16 11:54:57 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static char	*nbr_len(unsigned long nbr, int *len)
{
	char	*str;

	while (nbr >= 16)
	{
		nbr = nbr / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

void	if_hex(t_print *arg_count, char c)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	nbr = va_arg(arg_count->args, unsigned int);
	len = 1;
	str = nbr_len(nbr, &len);
	len--;
	while (len >= 0)
	{
		if (nbr % 16 < 10)
			str[len] = '0' + (nbr % 16);
		else if (c == 'x')
			str[len] = 'a' - 10 + (nbr % 16);
		else if (c == 'X')
			str[len] = 'A' - 10 + (nbr % 16);
		nbr = nbr / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	if_ptr(t_print *arg_count)
{
	unsigned long	nbr;
	int				len;
	char			*str;

	nbr = va_arg(arg_count->args, unsigned long);
	len = 1;
	str = nbr_len(nbr, &len);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	len--;
	while (len >= 0)
	{
		if (nbr % 16 < 10)
			str[len] = '0' + (nbr % 16);
		else
			str[len] = 'a' + (nbr % 16) - 10;
		nbr = nbr / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	if_char(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}

void	if_str(t_print *arg_count)
{
	char	*str;
	int		len;

	str = va_arg(arg_count->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arg_count->counter += len;
	}
}
