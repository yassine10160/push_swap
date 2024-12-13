/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:35:28 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/12/13 14:53:26 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack{

	int		size;
	int		pos;
	char	c;
	int		*tab;
	int		realpos;
} t_stack;

enum	e_state
{
	OPS,
	COST,
};

void	swap(t_stack s, char c);
void	push(t_stack *s1, t_stack *s2, char c);
void	rotate(t_stack *s, char c);
void	swap_both(t_stack s1, t_stack s2);
void	reverse_rotate(t_stack *, char c);
void	reverse_rotate_both(t_stack s1, t_stack s2);
void	rotate_both(t_stack s1, t_stack s2);
int		ft_atoi(const char *str);
int		is_new_biggest_or_smallest(int n, t_stack b);
int		pos_of_biggest(t_stack b);
int		bring_to_top_cost(int pos, t_stack *s, enum e_state e, char c);
int		nearest_big(t_stack b, int pso);
int		is_middle_top(t_stack a, int pos);
int		operation_cost(t_stack a,t_stack b, enum e_state e);
int		least_operation_cost(t_stack *a, t_stack *b, enum e_state e);
int		find_min(int a, int b);
int		find_min_operation(int a, int b, int c, int d);
void	up_or_down_option(t_stack *a, t_stack *b, int option);
void	do_ops_least_option(t_stack *a, t_stack *b);

#endif