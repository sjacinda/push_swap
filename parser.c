/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:13 by sjacinda          #+#    #+#             */
/*   Updated: 2022/01/27 18:24:19 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parser(char **argv, int argc)
{
	int		i;
	t_stack	*new;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		check_valid_number(argv[i]);
		new = new_stack(ft_atoi(argv[i]));
		if (new == NULL)
			exit_msg("Error: Malloc");
		stack_add_back(&stack, new);
		i++;
	}
	check_valid_stack(stack);
	return (stack);
}

void	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	check_valid_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				exit_msg("Error: Dublicate");
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

int	check_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->next->index - stack->index) == 1)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	check_valid_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
	{
		i++;
		if (!ft_isdigit((int)number[i]))
			exit_msg("Error: Invalid argument");
	}
	while (number[i])
	{
		if (!ft_isdigit((int)number[i]))
			exit_msg("Error: Invalid argument");
		i++;
	}
}
