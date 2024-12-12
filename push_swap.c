/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/12 18:03:08 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stack(t_stack a)
{
	printf("size: %d\n", a.size);
	for (int i = 0; i < a.size; i++)
	{
		printf("%d\n", a.tab[i]);
	}
}

int	operation_cost(t_stack a,int pos, t_stack b, enum e_state e)
{
	int	i;
	int	cost;

	i = 0;
	cost = 0;
	if ((is_middle_top(a, pos) && is_middle_top(b, nearest_big(b, a.tab[pos])))
		|| (!is_middle_top(a, pos) && !is_middle_top(b, nearest_big(b, a.tab[pos]))))
	{
		cost += bring_to_top_cost(pos, &a, e, 'a');
		if (is_new_biggest_or_smallest(a.tab[pos], b))
			cost += bring_to_top_cost(pos_of_biggest(b), &b, e, 'b');
		else
			cost += bring_to_top_cost(nearest_big(b, a.tab[pos]), &b, e, 'b');
	}
	else
	{
		
	}
	return (cost);
}

int	least_operation_cost(t_stack a, t_stack b)
{
	int	i;
	int	cost;
	int	tmp;

	i = a.size - 1;
	cost = operation_cost(a, i, b, COST);
	// faire  la fonction operation cost 
	while (i >= 0)
	{
		tmp = operation_cost(a, i, b, COST);
		if (tmp < cost)
			cost = tmp;
		i--;
	}
	return (cost);
}

// check input : faut pas qu'il y ait deux nombres egaux. verifier int max
#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		j;

	j = 0;
	i = ac - 1;
	a.tab = (int *)malloc((ac - 1) * sizeof(int));
	b.tab = (int *)malloc((ac - 4) * sizeof(int));
	a.size = ac - 1;
	b.size = 0;
	while (i > 0)
	{
		a.tab[j] = ft_atoi(av[i]);
		i--;
		j++;
	}
	push(&b, &a, 'b');
	push(&b, &a, 'b');
	print_stack(b);
	print_stack(a);
	j = least_operation_cost(a, b);
	printf("cost: %d\n", j);
	// sort_stack(a, b);
}
