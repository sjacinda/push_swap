/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:21 by sjacinda          #+#    #+#             */
/*   Updated: 2022/01/27 18:34:10 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	stack_add_back(t_stack **stack, t_stack *new);
void	sorting(t_stack *stack_a, t_stack *stack_b);
void	exit_msg(char *msg);
void	check_valid_stack(t_stack *stack);
void	check_valid_number(char *number);
void	indexator(t_stack *stack);
int		stack_size(t_stack *stack);
int		check_sorted(t_stack *stack);
t_stack	*new_stack(int value);
t_stack	*find_last(t_stack *stack);
t_stack	*find_pre_last(t_stack *stack);
t_stack	*parser(char **argv, int argc);

#endif
