/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:26 by yafahfou          #+#    #+#             */
/*   Updated: 2025/01/15 13:50:30 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//des erreurs dans le two check
// int	is_two_check(char *s)
// {
// 	int		i;
// 	char	**split;
// 	int		j;
// 	int		k;

// 	k = -1;
// 	split = ft_split(s, ' ');
// 	while (++k < count_word(s, ' '))
// 	{
// 		i = -1;
// 		while (split[k][++i] != '\0')
// 		{
// 			j = i;
// 			while (split[k][j] != '\0')
// 			{
// 				j++;
// 				if ((split[k][i] == '-' || split[k][j] == '-') && split[k][j]
// 					&& !is_dgt(split[k][j]))
// 					return (0);
// 				else if (split[k][i] && !is_dgt(split[k][i]) && !is_dgt(split[k][j]))
// 					return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }

int	is_two_check(char *s)
{
	int		i;
	char	**split;
	int		j;
	int		k;

	k = -1;
	split = ft_split(s, ' ');
	while (++k < count_word(s, ' '))
	{
		i = -1;
		while (split[k][++i] != '\0')
		{
			j = i;
			while (split[k][j] != '\0')
			{
				j++;
				if ((split[k][i] == '-' || split[k][j] == '-') && split[k][j]
					&& !is_dgt(split[k][j]))
					return (0);
				else if (split[k][i] != '-' && !is_dgt(split[k][i]) && !is_dgt(split[k][j]))
					return (0);
			}
		}
	}
	free_tab_str(split);
	return (1);
}

int is_already_sorted(t_stack *a, t_stack *b)
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
	__builtin_printf("je suis la\n");
	free_stacks(a, b);
	return (1);
}
int	handle_error()
{
	write(2, "Error\n", 6);
	return (1);
}
