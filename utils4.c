/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:48:45 by yafahfou          #+#    #+#             */
/*   Updated: 2025/01/10 13:18:45 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (b.tab[i] < element && b.tab[i] >= near)
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
	near = INT_MAX;
	pos = -1;
	while (i < a.size)
	{
		if (a.tab[i] > element && a.tab[i] <= near)
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