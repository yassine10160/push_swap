/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:26 by yafahfou          #+#    #+#             */
/*   Updated: 2025/02/21 15:34:30 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_two_check(char *s)
{
	int		i;
	char	**p;
	int		j;
	int		k;

	k = -1;
	p = ft_split(s, ' ');
	while (++k < count_word(s, ' '))
	{
		i = -1;
		while (p[k][++i] != '\0')
		{
			j = i;
			while (p[k][j] != '\0')
			{
				j++;
				if ((p[k][i] == '-' || p[k][j] == '-') && !is_dgt(p[k][i + 1]))
					return (0);
				else if (p[k][i] != '-' && !is_dgt(p[k][i]) && !is_dgt(p[k][j]))
					return (0);
			}
		}
	}
	free_tab_str(p);
	return (1);
}

int	is_already_sorted(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->tab[i] < a->tab[j])
				return (0);
			j++;
		}
		i++;
	}
	free_stacks(a, b);
	return (1);
}

int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
}

int	is_dgt(char c)
{
	if ('0' <= (unsigned char)c && (unsigned char)c <= '9')
		return (1);
	return (0);
}
