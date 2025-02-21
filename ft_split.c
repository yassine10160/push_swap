/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:45:11 by yafahfou          #+#    #+#             */
/*   Updated: 2025/02/07 12:41:40 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	count_word(char const *s, char c)
{
	int	index;
	int	cpt;

	index = 0;
	cpt = 0;
	while (s && *s)
	{
		if (*s != c && index == 0)
		{
			index = 1;
			cpt++;
		}
		else if (*s == c)
			index = 0;
		s++;
	}
	return (cpt);
}

char	*ft_dup(char *s, int start, int finish)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc((finish - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	**free_split(char **split, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	ssize_t	i;
	int		j;
	int		index;
	char	**split;

	i = -1;
	index = -1;
	j = 0;
	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (++i <= (ssize_t)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (ssize_t)ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_dup((char *)s, index, i);
			if (!split[j++])
				return (free_split(split, j));
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
