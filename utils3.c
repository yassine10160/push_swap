/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:47:06 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/18 13:48:38 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bring_to_top_cost(int pos, t_stack *s, enum e_state e, char c)
{
	int	i;

	i = -1;
	if (pos == s->size - 1)
		return (0);
	else if (pos + 1 > (s->size / 2) || s->c == 'u')
	{
		while (++i < s->size - (pos + 1))
		{
			if (e == OPS)
				rotate(s, c);
		}
	}
	else if (pos + 1 <= (s->size / 2) || s->c == 'd')
	{
		while (++i < pos + 1)
		{
			if (e == OPS)
				reverse_rotate(s, c);
		}
	}
	if (pos == 0)
		i = 1;
	return (i);
}
void	both_up_option(t_stack *a, t_stack *b)
{
	int	realsize;
	int	i;
	
	i = 0;
	realsize =  find_min((a->size - (a->pos + 1)),(b->size - (b->pos + 1)));
	while (i < realsize)
	{
		rotate_both(*a, *b);
		i++;
	}
	bring_to_top_cost(a->pos + i, a, OPS, 'a');
	bring_to_top_cost(b->pos + i, b, OPS, 'b');
}
void	both_down_option(t_stack *a, t_stack *b)
{
	int	realsize;
	int	i;
	int	apos;
	int	bpos;

	i = 0;
	apos = a->pos;
	bpos = b->pos;
	realsize = find_min((a->pos + 1), (b->pos + 1));
	while (i < realsize)
	{
		reverse_rotate_both(*a, *b);
		apos--;
		bpos--;
		if (apos == -1)
			apos = a->size - 1;
		else if (bpos == -1)
			bpos = b->size - 1;
		i++;
	}
	bring_to_top_cost(apos, a, OPS, 'a');
	bring_to_top_cost(bpos, b, OPS, 'b');
}
void	do_ops_least_option(t_stack *a, t_stack *b)
{
	if (a->c == 'd' && b->c == 'd')
		both_down_option(a, b);
	else if (a->c == 'u' && b->c == 'u')
		both_up_option(a, b);
	else
	{
		bring_to_top_cost(a->pos, a, OPS, 'a');
		bring_to_top_cost(b->pos, b, OPS, 'b');
	}
}
void	up_or_down_option(t_stack *a, t_stack *b, int option)
{
	if (option == 1)
	{
		a->c = 'u';
		b->c = 'u';
	}
	else if (option == 2)
	{
		a->c = 'u';
		b->c = 'd';
	}
	else if (option == 3)
	{
		a->c = 'd';
		b->c = 'u';
	}
	else
	{
		a->c = 'd';
		b->c = 'd';
	}
	do_ops_least_option(a, b);
}