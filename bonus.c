/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:16:51 by sjacinda          #+#    #+#             */
/*   Updated: 2022/01/27 18:16:54 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_command(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp("sa", line, 3))
		sa(&stack_a);
	else if (!ft_strncmp("sb", line, 3))
		cb(&stack_b);
	else if (!ft_strncmp("ss", line, 3))
		ss(&stack_a, &stack_b);
	else if (!ft_strncmp("pa", line, 3))
		pa(&stack_a, &stack_b);
	else if (!ft_strncmp("pb", line, 3))
		pb(&stack_a, &stack_b);
	else if (!ft_strncmp("ra", line, 3))
		ra(&stack_a);
	else if (!ft_strncmp("rb", line, 3))
		rb(&stack_b);
	else if (!ft_strncmp("rr", line, 3))
		rr(&stack_a, &stack_b);
	else if (!ft_strncmp("rra", line, 3))
		rra(&stack_a);
	else if (!ft_strncmp("rrb", line, 3))
		rrb(&stack_b);
	else if (!ft_strncmp("rrr", line, 3))
		rrr(&stack_a, &stack_b);
	else
		exit_msg("Eror: Unknow command");
}

int	main(int argc, char **ergv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = parser(argv, argc);
	line = get_next_line(0);
	while (line)
	{
		check_command(line, stack_a, stack_b);
		line = get_next_line(0);
	}
	if (!stack_b && charck_sorted(stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	exit(0);
}
