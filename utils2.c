/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/17 19:52:25 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_stack a, t_stack b)
{
	reverse_rotate(&a,'n');
	reverse_rotate(&b, 'n');
	write(1, "rrr\n", 4);
}
void	rotate_both(t_stack a, t_stack b)
{
	rotate(&a, 'n');
	rotate(&b, 'n');
	write(1, "rr\n", 3);
}
int     ft_atoi(const char *str)
{
        size_t  i;
        long    total;
        long    sign;

        i = 0;
        total = 0;
        sign = 1;
        while (str && (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r')))
                i++;
        if (str && (str[i] == '-' || str[i] == '+'))
        {
                if (str[i] == '-')
                        sign = -1;
                i++;
        }
        while (str && ('0' <= str[i] && str[i] <= '9'))
        {
                total = (total * 10) + (str[i] - 48);
                i++;
        }
        return (total * sign);
}
int	is_new_biggest_or_smallest(int n, t_stack b)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 1;
	while (i < b.size)
	{
		if (b.tab[i] > n)
			trigger = 0;
		i++;
	}
	if (trigger == 1)
		return (1);
	i = 0;
	trigger = 1;
	while (i < b.size)
	{
		if (b.tab[i] < n)
			trigger = 0;
		i++;
	}
	if (trigger == 1)
		return (1);
	return (0);
}

int	pos_of_biggest(t_stack b)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = INT_MIN;
	pos = INT_MIN;
	while (i < b.size)
	{
		if (b.tab[i] > max)
		{
			max = b.tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

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

int	is_middle_top(t_stack a, int pos)
{
	if (pos + 1 >= a.size / 2)
		return (1);
	else
		return (0);
}
int	nearest_big(t_stack b, int element)
{
	int	near;
	int	i;
	int	pos;


	i = 0;
	near = INT_MIN;
	pos = -1;
	while (i < b.size)
	{
		if (b.tab[i] < element && b.tab[i] > near)
		{
			near = b.tab[i];
			pos = i;
		}
		i++;
	}
	if (b.c == 'z')
		return (near);
	return (pos);
}
int	nearest_small(t_stack a, int element)
{
	int	near;
	int	i;
	int	pos;


	i = 0;
	a.c = 'z';
	near = INT_MAX;
	pos = -1;
	while (i < a.size)
	{
		if (a.tab[i] > element && a.tab[i] < near)
		{
			near = a.tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
int	find_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
int	find_min_operation(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return(a);
	else if (b <= a && b <= c && b <= d)
		return (b);
	else if (c <= a && c <= b && c <= d)
		return (c);
	else
		return (d);
}
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