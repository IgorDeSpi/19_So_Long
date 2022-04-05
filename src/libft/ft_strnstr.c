/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:12:51 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/04 16:22:39 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = -1;
		while (haystack[++i] && haystack[i] == needle[i] && len - i)
		{
			if (!needle[i + 1])
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (NULL);
}
