/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/13 14:52:01 by yafahfou         ###   ########.fr       */
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

	i = 1;
	max = b.tab[0];
	while (i < b.size)
	{
		if (b.tab[i] > max)
			max = i;
		i++;
	}
	if (max == b.tab[0])
		return(0);
	return (max);
}
int	bring_to_top_cost(int pos, t_stack *s, enum e_state e, char c)
{
	int	i;

	i = 0;
	if (pos == s->size - 1)
		return (0);
	else if (pos + 1 >= s->size / 2 || s->c == 'u')
	{
		while (i < s->size - (pos + 1))
		{
			if (e == OPS)
				rotate(s, c);
			i++;
		}
	}
	else if (pos + 1 < s->size / 2 || s->c == 'd')
	{
		while (i < s->size - (pos + 2))
		{
			if (e == OPS)
				reverse_rotate(s, c);
			i++;
		}
	}
	return (i);
}

void	do_ops_least_option(t_stack *a, t_stack *b)
{
	bring_to_top_cost(a->pos, a, OPS, 'a');
	bring_to_top_cost(b->pos, b, OPS, 'b');
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
	if (pos + 1 > a.size / 2)
		return (1);
	else
		return (0);
}
int	nearest_big(t_stack b, int pos)
{
	int	near;
	int	i;
	int	element;

	element = b.tab[pos];
	i = 0;
	near = b.tab[0];
	while (i < b.size)
	{
		if (b.tab[i] < element && b.tab[i] > near)
			near = i;
		i++;
	}
	return (near);
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
