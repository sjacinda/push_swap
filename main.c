#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("i = %d  value = %d index = %d\n", i, stack->value, stack->index);
		i++;
		stack = stack->next;
	}
}

void	indexator(t_stack *stack)
{
	int	index;
	t_stack	*tmp;
	t_stack	*head;

	head = stack;
	while (stack)
	{
		index = 0;
		tmp = head;
		while (tmp)
		{
			if (stack->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		stack->index = index;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc = 3)
		exit_msg("Error: Not enough arguments");
	stack = parser(argv, argc);
	indexator(stack);
	if (check_sorted(stack))
		exit (0);
	sorting(stack, NULL);
	return (0);
}
