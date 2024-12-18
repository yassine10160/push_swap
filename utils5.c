/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:50:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/18 13:58:40 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_new_smallest(int n, t_stack b)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 1;
	while (i < b.size)
	{
		if (b.tab[i] < n)
			trigger = 0;
		i++;
	}
	return(trigger);
}
int	pos_of_smallest(t_stack b)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = INT_MAX;
	pos = INT_MAX;
	while (i < b.size)
	{
		if (b.tab[i] < max)
		{
			max = b.tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
/**
 * @warning this function only works if the size of the stack is equal to three
 **/
int	is_sorted(t_stack*a)
{
	if (a->tab[a->size -1] > a->tab[a->size -2]
		&& a->tab[a->size - 2] > a->tab[0])
			return (0);
	else if (a->tab[a->size - 1] < a->tab[a->size -2]
		&& a->tab[a->size - 2] > a->tab[0]
		&& a->tab[a->size - 1] < a->tab[0])
			return (0);
	return (1);	
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
void	do_choice(t_stack *a, t_stack *b, int choice)
{
	up_or_down_option(a, b, choice);
}