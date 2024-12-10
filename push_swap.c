/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:41 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/10 18:42:51 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stack(t_stack s)
{
	printf("size: %d\n", s.size);
	for (int i = 0; i < s.size; i++)
	{
		printf("%d\n", s.tab[i]);
	}
}
#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack	s;
	t_stack	s2;
	int		i;
	int		j;

	j = 0;
	i = ac - 1;
	s.tab = (int *)malloc((ac - 1) * sizeof(int));
	s2.tab = (int *)malloc((ac - 4) * sizeof(int));
	s.size = ac - 1;
	s2.size = 0;
	while (i > 0)
	{
		s.tab[j] = ft_atoi(av[i]);
		i--;
		j++;
	}
	// s2.tab[0] = 9;
	// printf("%d\n", s2.tab[0]);
	// s2.tab[1] = 11;
	// swap(s);
	print_stack(s);
	push(&s2, &s, 'b');
	// swap_both(s, s2);
	//reverse_rotate_both(s, s2);
	//print_stack(s);
	print_stack(s2);
}
