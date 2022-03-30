/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:05:37 by ide-spir          #+#    #+#             */
/*   Updated: 2022/02/16 11:11:19 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	nbr_len(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*my_u_itoa(unsigned int nbr)
{
	char	*str;
	int		len;

	len = nbr_len(nbr);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

void	if_int(t_print *arg_count)
{
	char	*str;
	int		res;

	res = va_arg(arg_count->args, int);
	str = ft_itoa(res);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}

void	if_u_int(t_print *arg_count)
{
	char			*str;
	unsigned int	res;

	res = va_arg(arg_count->args, unsigned int);
	str = my_u_itoa(res);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}
