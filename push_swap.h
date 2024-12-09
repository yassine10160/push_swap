/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:35:28 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/12/09 16:21:32 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
typedef struct s_stack{

	int	size;
	int	value;
	int	pos;
	int	realpos;
	int	*tab;
} t_stack;

void	swap(t_stack s);
void	push_a(t_stack s1, t_stack s2);


#endif