/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/18 15:45:20 by yafahfou         ###   ########.fr       */
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

// check input : faut pas qu'il y ait deux nombres egaux. verifier int max
void	handle_many_args(t_stack *a, char **av, int ac)
{
	int	i;
	int	j;

	i = ac - 1;
	j = 0;
	a->tab = (int *)malloc((ac - 1) * sizeof(int));
	a->size = ac - 1;
	while (i > 0)
		a->tab[j++] = ft_atoi(av[i--]);
}
void	handle_two_args(t_stack *a, char *s)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(s, ' ');
	i = count_word(s, ' ');
	j = 0;
	a->tab = (int *)malloc((i) * sizeof(int));
	a->size = i;
	while (i > 0)
		a->tab[j++] = ft_atoi(split[i--]);
}

int	is_check(char **av)
{
	if (av)
		return (1);
	return (0);
}
//verifier qu ma liste estd deja triee , (faire  une fonction pour ca)
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (is_check(av))
	{
		if (ac == 2)
		{
			handle_two_args(&a, av[1]);
		}
		else
			handle_many_args(&a, av, ac);	
		b.tab = (int *)malloc((ac - 4) * sizeof(int));
		b.size = 0;
		push(&b, &a, 'b');
		push(&b, &a, 'b');
		push_swap(a, b);
	}

}
