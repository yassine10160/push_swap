/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/12 17:49:03 by yafahfou         ###   ########.fr       */
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
int	bring_to_top_cost(int pos, t_stack *b, enum e_state e, char c)
{
	int	i;

	i = 0;
	if (pos == b->size - 1)
		return (0);
	else if (pos + 1 > b->size / 2)
	{
		while (i < b->size - (pos + 1))
		{
			if (e == OPS)
				rotate(b, c);
			i++;
		}
	}
	else
	{
		while (i < b->size - (pos + 2))
		{
			if (e == OPS)
				reverse_rotate(b, c);
			i++;
		}
	}
	return (i);
}

int	is_middle_top(t_stack a, int pos)
{
	if (pos + 1 > a.size / 2)
		return (1);
	else
		return (0);
}
int	nearest_big(t_stack b, int element)
{
	int	near;
	int	i;

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
