/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:31:37 by yafahfou          #+#    #+#             */
/*   Updated: 2025/01/15 14:57:53 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_many_args(t_stack *a, t_stack *b, char **av, int ac)
{
	int	i;
	int	j;

	i = ac - 1;
	j = 0;
	a->tab = (int *)malloc((ac - 1) * sizeof(int));
	a->size = ac - 1;
	while (i > 0)
	{
		a->tab[j] = ft_atoi(av[i]);
		if (a->tab[j] == -1 && ft_strncmp(av[i], "-1", 2))
		{
			handle_error();
			free(a->tab);
			exit(1);
		}
		j++;
		i--;
	}
	b->size = 0;
	b->tab = (int *)malloc((ac - 4) * sizeof(int));
}
void free_tab_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
void	handle_two_args(t_stack *a, char *s, t_stack *b)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(s, ' ');
	i = count_word(s, ' ');
	j = 0;
	a->tab = (int *)malloc((i) * sizeof(int));
	a->size = i;
	i = i - 1;
	while (i > 0)
	{
		a->tab[j] = ft_atoi(split[i]);
		if (a->tab[j] == -1 && ft_strncmp(split[i], "-1", 2))
		{
			handle_error();
			free(a->tab);
			exit(1);
		}
		j++;
		i--;
	}
	free_tab_str(split);
	b->tab = (int *)malloc((count_word(s, ' ')) * sizeof(int));
	b->size = 0;
}

int	is_double_or_max(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size)
	{
		j = i + 1;
		while (j < a.size)
		{
			__builtin_printf("indice de i %d\n", j);
			__builtin_printf("size %d\n", a.size);
			if (a.tab[i] == a.tab[j])
				return (1);
			else if (a.tab[i] > INT_MAX || a.tab[i] < INT_MIN)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_dgt(char c)
{
	if ('0' <= (unsigned char)c && (unsigned char)c <= '9')
		return (1);
	return (0);
}

int	is_check(int ac, char **av)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (++k < ac)
	{
		i = -1;
		while (av[k][++i] != '\0')
		{
			j = i;
			while (av[k][j] != '\0')
			{
				j++;
				if (av[k][i] == '-')
				{
					if (av[k][j] && !is_dgt(av[k][j]))
						return (0);
				}
				else if (!is_dgt(av[k][i]) || (av[k][j] && !is_dgt(av[k][j])))
					return (0);
			}
		}
	}
	return (1);
}
