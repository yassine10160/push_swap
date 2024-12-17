/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:34 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stack(t_stack a)
{
	printf("size: %d\n", a.size);
	for (int i = a.size - 1; i >= 0; i--)
	{
		printf("%d\n", a.tab[i]);
	}
}
void	do_choice(t_stack *a, t_stack *b, int choice)
{
	up_or_down_option(a, b, choice);
}
int	least_option(t_stack *a, int posb, t_stack *b, enum e_state e)
{
	t_option	o;

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
		if (o.res == o.op1)
			a->choice = 1;
		else if (o.res == o.op2)
			a->choice = 2;
		else if (o.res == o.op3)
			a->choice = 3;
		else
			a->choice = 4;
	}
	else
		do_choice(a, b, a->realchoice);
	return (o.res);
}
int	operation_cost(t_stack *a, t_stack *b, enum e_state e)
{
	int	cost;
	int	posb;

	cost = 0;
	if (is_new_smallest(a->tab[a->pos], *b))
	{
		posb = pos_of_biggest(*b);
		cost = least_option(a, posb, b, e);
	}
	else
	{
		posb = nearest_big(*b, a->tab[a->pos]);
		cost = least_option(a, posb, b, e);
	}
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
	cost = operation_cost(a, b, e);
	a->realchoice = a->choice;
	i = i - 1;
	while (i >= 0)
	{
		a->pos = i;
		tmp = operation_cost(a, b, e);
		if (tmp < cost)
		{
			a->realchoice = a->choice;
			cost = tmp;
			a->realpos = i;
		}	
		i--;
	}
	a->pos = a->realpos;
	return (cost);
}
/**
 * @warning this function only works if the size of the stack is equal to three
 */
int	is_sorted(t_stack*a)
{
	if (a->tab[a->size -1] > a->tab[a->size -2]
		&& a->tab[a->size - 2] > a->tab[0])
			return (0);
	else if (a->tab[a->size - 1] < a->tab[a->size -2]
		&& a->tab[a->size - 2] > a->tab[0])
			return (0);
	return (1);	
}
void	sort_three(t_stack *a)
{
	if (!is_sorted(a))
		swap(*a, 'a');
}

void	push_swap(t_stack a, t_stack b)
{
	int	pos;
	int	i;

	i = 0;
	while (a.size > 3)
	{
		
		least_operation_cost(&a, &b, COST);
		operation_cost(&a, &b, OPS);
		push(&b, &a, 'b');
	}
	sort_three(&a);
	while (b.size > 0)
	{
		pos = nearest_small(a,b.tab[i]);
		if (pos != a.size - 1)
			bring_to_top_cost(pos, &a, OPS, 'n');
		push(&a, &b, 'a');
		i++;
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
