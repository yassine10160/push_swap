/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/11 15:34:43 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_stack s1, t_stack s2)
{
	reverse_rotate(s1);
	reverse_rotate(s2);
}
void	rotate_both(t_stack s1, t_stack s2)
{
	rotate(s1);
	rotate(s2);
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
int	bring_to_top_cost(int pos, t_stack b)
{
	int	i;

	if (pos + 1 >= b.size)
	{
		
	}
}