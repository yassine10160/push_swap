/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:54:25 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/12/10 18:31:31 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack s, char c)
{
	int	tmp;
	int	size;

	size = s.size;
	if (size > 1)
	{
		tmp = s.tab[size - 2];
		s.tab[size - 2] = s.tab[size - 1];
		s.tab[size - 1] = tmp;
	}
	if (c == 's')
		write(1, "ss\n", 3);
	else if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}
void	push(t_stack *s1, t_stack *s2, char c)
{
	if (s2->size > 0)
	{
		s1->tab[s1->size] = s2->tab[s2->size - 1];
		s1->size += 1;
		s2->size--;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
void	swap_both(t_stack s1, t_stack s2)
{
	swap(s1, 's');
	swap(s2, 's');
}

void	reverse_rotate(t_stack s)
{
	int	i;
	int	tmp;

	i = s.size -1;
	while (i > 0)
	{
		tmp = s.tab[i];
		s.tab[i] = s.tab[i - 1];
		s.tab[i - 1] = tmp;
		i--;
	}
}

void	rotate(t_stack s)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < s.size - 1)
	{
		tmp = s.tab[i];
		s.tab[i] = s.tab[i + 1];
		s.tab[i + 1] = tmp;
		i++;
	}
}