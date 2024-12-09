/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:54:25 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/12/09 23:43:20 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack s)
{
	int	tmp;
	int	size;

	size = s.size;
	if (size > 1)
	{
		tmp = s.tab[size - 2];
		s.tab[size - 2] = s.tab[size - 1];
		s.tab[size - 1] = tmp;
	}
}
void	push(t_stack *s1, t_stack *s2)
{
	if (s2->size > 0)
	{
		s1->tab[s1->size] = s2->tab[s2->size - 1];
		s1->size += 1;
		s2->size--;
	}
}
void	swap_both(t_stack s1, t_stack s2)
{
	swap(s1);
	swap(s2);
}
void	rotate(t_stack s)
{
	int	i;
	int	tmp;
	int	first;

	i = 0;
	first = s.tab[s.size - 1];
	while (i < s.size)
	{
		
	}
}
void	print_stack(t_stack s)
{
	printf("size: %d\n", s.size);
	for (int i = 0; i < s.size; i++)
	{
		printf("%d\n", s.tab[i]);
	}
}
int	main()
{
	t_stack	s;
	t_stack	s2;

	s.tab = (int *)malloc(15 * sizeof(int));
	s2.tab = (int *)malloc(2 * sizeof(int));
	s.size = 9;
	s2.size = 2;
	s2.tab[0] = 9;
	// printf("%d\n", s2.tab[0]);
	s2.tab[1] = 11;
	for (int i = 0; i < 9; i++)
		s.tab[i] = i;
	// swap(s);
	// print_stack(s);
	push(&s, &s2);
	swap_both(s, s2);
	print_stack(s);
}