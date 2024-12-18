/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/18 13:54:18 by yafahfou         ###   ########.fr       */
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
