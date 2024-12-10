/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:35:28 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/12/10 18:50:47 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_stack{

	int	size;
	int	value;
	int	pos;
	int	realpos;
	int	*tab;
} t_stack;

void	swap(t_stack s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack s);


#endif
