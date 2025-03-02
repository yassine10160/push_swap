/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:35:28 by yassinefahf       #+#    #+#             */
/*   Updated: 2025/02/21 14:11:08 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		size;
	int		pos;
	char	c;
	int		*tab;
	int		realpos;
	int		choice;
	int		realchoice;

}	t_stack;

typedef struct s_option
{
	int	op1;
	int	op2;
	int	op3;
	int	op4;
	int	res;
	int	min;
}	t_option;

enum	e_state
{
	OPS,
	COST,
};

void	swap(t_stack *s, char c);
void	push(t_stack *s1, t_stack *s2, char c);
void	rotate(t_stack *s, char c);
void	swap_both(t_stack *s1, t_stack *s2);
void	reverse_rotate(t_stack *s, char c);
void	reverse_rotate_both(t_stack *s1, t_stack *s2);
void	rotate_both(t_stack *s1, t_stack *s2);
int		ft_atoi(const char *str);
int		is_new_biggest_or_smallest(int n, t_stack *b);
int		pos_of_biggest(t_stack *b);
int		bring_to_top_cost(int pos, t_stack *s, enum e_state e, char c);
int		nearest_big(t_stack *b, int element);
int		is_middle_top(t_stack *a, int pos);
int		operation_cost(t_stack *a, t_stack *b, enum e_state e);
int		least_operation_cost(t_stack *a, t_stack *b, enum e_state e);
int		find_min(int a, int b);
int		find_min_operation(int a, int b, int c, int d);
void	up_or_down_option(t_stack *a, t_stack *b, int option);
void	do_ops_least_option(t_stack *a, t_stack *b);
int		is_new_smallest(int n, t_stack *b);
int		nearest_small(t_stack *a, int element);
int		pos_of_smallest(t_stack *b);
int		is_sorted(t_stack*a);
void	do_choice(t_stack *a, t_stack *b, int choice);
int		least_option(t_stack *a, int posb, t_stack *b, enum e_state e);
int		count_word(char const *s, char c);
char	**ft_split(char const *s, char c);
int		is_two_check(char *s);
int		is_already_sorted(t_stack *a, t_stack *b);
int		handle_error(void);
void	handle_many_args(t_stack *a, t_stack *b, char **av, int ac);
void	handle_two_args(t_stack *a, char *s, t_stack *b);
int		is_double_or_max(t_stack *a, t_stack *b);
int		is_dgt(char c);
int		is_check(int ac, char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_stacks(t_stack *a, t_stack *b);
void	free_tab_str(char **s);
#endif
