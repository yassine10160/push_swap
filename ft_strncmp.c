/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:43:01 by yassine           #+#    #+#             */
/*   Updated: 2025/01/08 11:46:47 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
	{
		if (!s2)
			return (0);
		return (-(unsigned char)s2[i]);
	}
	else if (!s2)
		return ((unsigned char)s1[i]);
	while (i < n && s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
