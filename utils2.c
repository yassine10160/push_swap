/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:50:31 by yafahfou          #+#    #+#             */
/*   Updated: 2024/12/10 16:53:14 by yafahfou         ###   ########.fr       */
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