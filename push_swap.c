/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2025/01/15 13:30:25 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack *a)
{
	int	pos;
	
	if (!is_sorted(a))
		swap(*a, 'a');
	pos = pos_of_smallest(*a);
	if (a->tab[a->size - 1] > a->tab[a->size -2]
		&& a->tab[a->size - 2] < a->tab[0]
		&& a->tab[a->size - 1] < a->tab[0])
			swap(*a, 'a');
	else
		bring_to_top_cost(pos, a, OPS, 'a');
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
	a.c = 'y';
	sort_three(&a);
	while (b.size > 0)
	{
		i = b.size - 1;
		pos = nearest_small(a,b.tab[i]);
		if (pos == -1) 
			pos = pos_of_smallest(a);
		bring_to_top_cost(pos, &a, OPS, 'a');
		push(&a, &b, 'a');
	}
	pos = pos_of_smallest(a);
	bring_to_top_cost(pos, &a, OPS, 'a');
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
}
// verifier les int max et les int min. la verif n'est pas bonne, je vais le faire avec les fcts handles;
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 2)
	{
		if (!is_two_check(av[1]))
			return (handle_error());
		handle_two_args(&a, av[1], &b);
	}
	else
	{
		if (!is_check(ac, av))
			return(handle_error());
		handle_many_args(&a, &b, av, ac);
	}
	if (is_double_or_max(a))
		return (handle_error());
	if (is_already_sorted(&a, &b))
		return (0);
	if (a.size > 3)
		push(&b, &a, 'b');
	if (a.size > 3)
		push(&b, &a, 'b');
	push_swap(a, b);
	free_stacks(&a, &b);
}
