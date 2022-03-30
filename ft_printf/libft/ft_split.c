/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-spir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:52:02 by ide-spir          #+#    #+#             */
/*   Updated: 2022/01/11 16:38:56 by ide-spir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(const char *s, char c)
{
	size_t	nb_strings;

	nb_strings = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nb_strings++;
			continue ;
		}
		s++;
	}
	return (nb_strings);
}

static const char	*dup_until_c(char **cpy, const char *src, char c)
{
	size_t	len;
	size_t	i;

	while (*src == c)
		src++;
	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	*cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (*cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(*cpy)[i] = src[i];
		i++;
	}
	(*cpy)[i] = '\0';
	src += len + 1;
	return (src);
}

static void	free_strs(char ***strs, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	nb_strings;
	size_t	i;

	if (!s)
		return (NULL);
	nb_strings = count_strings(s, c);
	strs = (char **)malloc(sizeof(char *) * (nb_strings + 1));
	if (strs != NULL)
	{
		strs[nb_strings] = NULL;
		i = 0;
		while (i < nb_strings)
		{
			s = dup_until_c(strs + i, s, c);
			if (s == NULL)
			{
				free_strs(&strs, i);
				break ;
			}
			i++;
		}
	}
	return (strs);
}
