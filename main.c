#include "push_swap.h"
#include <stdio.h>
void print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		printf("index = %d value = %d\n", i, stack->value);
		i++;
		stack = stack->next;
	}
	
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	top;

	size = stack_size(stack_a);
	max_num = size - 1;
	max_bits = 0;
	while((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while(i < max_bits)
	{
		j = 0;
		while(j < size && stack_a)
		{
			top = stack_a->value;
			if (((top >> i)&1) == 1)
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
		i++;
	}
	while (stack_b)
	{
		ft_putendl_fd("pa", 1);
		pa(&stack_a, &stack_b);
	}
	print_stack(stack_a);
}


int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parser(argv, argc);
	indexator(stack);
	print_stack(stack);

	// sorting(stack, NULL);
	return (0);
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
		stack->value = index;
		stack = stack->next;
	}
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while(stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
