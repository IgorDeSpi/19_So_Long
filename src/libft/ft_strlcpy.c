/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:55:27 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/04 15:03:45 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char	*tmp;

	if (!dstsize)
		return (ft_strlen(src));
	tmp = (char *)src;
	dstsize--;
	while (*src && dstsize--)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(tmp));
}
