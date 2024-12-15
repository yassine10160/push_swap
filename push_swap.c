/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/15 17:28:39 by yafahfou         ###   ########.fr       */
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
int	least_option(t_stack *a, int posb, t_stack *b, enum e_state e)
{
	t_option o;
 
	b->pos = posb;
	if (e == COST)
	{
		o.min = find_min((a->size - (a->pos + 1)),(b->size - (posb + 1)));
		o.op1 = ((a->size - (a->pos + 1)) + (b->size - (posb + 1))) - o.min;
		o.op2 = (a->size - (a->pos + 1)) + (posb + 1);
		o.op3 = (a->pos + 1) + (b->size - (posb + 1));
		o.min = find_min((a->pos + 1), (posb + 1));
		o.op4 = ((a->pos + 1) + (posb + 1)) - o.min;
		o.res = find_min_operation(o.op1, o.op2, o.op3, o.op4);
	}
	else
	{
		if (o.res == o.op1)
			up_or_down_option(a, b, 1);
		else if (o.res == o.op2)
			up_or_down_option(a, b, 2);
		else if (o.res == o.op3)
			up_or_down_option(a, b, 3);
		else
			up_or_down_option(a, b, 4);
	}
	return (o.res);
}
// int	operation_cost(t_stack *a, t_stack *b, enum e_state e)
// {
// 	int	cost;
// 	int	realcost;

// 	cost = 0;
// 	if ((is_middle_top(*a, a->pos) && is_middle_top(*b, nearest_big(*b, a->pos)))
// 		|| (!is_middle_top(*a, a->pos) && !is_middle_top(*b, nearest_big(*b, a->pos))))
// 	{
// 		realcost = bring_to_top_cost(a->pos, a, e, 'a');
// 		if (is_new_biggest_or_smallest(a->tab[a->pos], *b))
// 			cost = bring_to_top_cost(pos_of_biggest(*b), b, e, 'b');
// 		else
// 			cost = bring_to_top_cost(nearest_big(*b, a->tab[a->pos]), b, e, 'b');
// 		if (realcost > cost)
// 			cost = realcost - cost;
// 		else
// 			cost = cost - realcost;
// 	}
// 	else
// 		cost = least_option(a, nearest_big(*b, a->tab[a->pos]), b, e);
// 	return (cost);
// }
int	operation_cost(t_stack *a, t_stack *b, enum e_state e)
{
	int	cost;

	cost = 0;
	if (is_new_smallest(a->tab[a->pos], *b))
		cost = least_option(a, pos_of_biggest(*b), b, e);
	else
		cost = least_option(a, nearest_big(*b, a->tab[a->pos]), b, e);
	return (cost);
}

int	least_operation_cost(t_stack *a, t_stack *b, enum e_state e)
{
	int	i;
	int	cost;
	int	tmp;

	i = a->size - 1;
	a->pos = i;
	a->realpos = i;
	// printf("realpos: %d\n", a->realpos);
	i--;
	cost = operation_cost(a, b, e);
	// faire  la fonction operation cost 
	while (i >= 0)
	{
		a->pos = i;
		tmp = operation_cost(a, b, e);
		if (tmp < cost)
		{
			cost = tmp;
			a->realpos = i;
		}	
		i--;
	}
	a->pos = a->realpos;
	return (cost);
}
void	push_swap(t_stack a, t_stack b)
{
	int res;

	while (a.size > 3)
	{
		
		res = least_operation_cost(&a, &b, COST);
		// res = least_option(&a, nearest_big(b, a.tab[a.pos]), &b, COST);
		// res = bring_to_top_cost(a.realpos);
		// printf("pos: %d\n", a.pos);
		res = operation_cost(&a, &b, OPS);
		push(&b, &a, 'b');
	}
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
	push_swap(a, b);
	// print_stack(b);
	// print_stack(a);
	// j = least_operation_cost(a, b);
	// printf("cost: %d\n", j);
	// sort_stack(a, b);
}
