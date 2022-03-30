/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:03:54 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/12 15:26:06 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*int_to_str(int n, int pow_ten, short sign, char *output)
{
	int	i;

	i = 0;
	if (sign == -1)
		i++;
	while (pow_ten)
	{
		output[i++] = (char)(n / pow_ten * sign + '0');
		n = n % pow_ten;
		pow_ten /= 10;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*dst;
	short	sign;
	int		power_ten;

	i = 1;
	power_ten = 1;
	sign = 0;
	if (n < 0)
		sign++;
	while (n / power_ten / 10 && i++)
		power_ten *= 10;
	dst = (char *)malloc(i + sign + 1);
	if (!dst)
		return (NULL);
	if (sign == 1)
	{
		dst[0] = '-';
		sign = -1;
	}
	else
		sign++;
	return (int_to_str(n, power_ten, sign, dst));
}
