/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:27 by sjacinda          #+#    #+#             */
/*   Updated: 2022/01/27 18:31:54 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	big_sort(t_stack *stack_a, t_stack *stack_b, int size, int max_bits);

void	printer(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a && !stack_b)
			printf("%5d %5s\n", stack_a->index, "");
		else if (!stack_a && stack_b)
			printf("%5s %5d\n", "", stack_b->index);
		else
			printf("%5s %5d\n", stack_a->index, stack_b->index);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	printf("%5s &5s\n", "_a_", "_b_");
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;

	size = stack_size(stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	if (size > 5)
		big_sort(stack_a, stack_b, size, max_bits);
	else
		small_sorts(stack_a, stack_b);
}

void	big_sort(t_stack *stack_a, t_stack *stack_b, int size, int max_bits)
{
	int	i;
	int	j;
	int	top;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && stack_a)
		{
			top = stack_a->index;
			if ((top >> i)&1)
			{
				ra(&stack_a);
				ft_putendl_fd("ra", 1);
			}
			else
			{
				pb(&stack_a, &stack_b);
				ft_putendl_fd("pb", 1);
			}
			j++;
		}
		while (stack_b)
		{
			ft_putendl_fd("pa", 1);
			pa(&stack_a, &stack_b);
		}
		i++;
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	
}
