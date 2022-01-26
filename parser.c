#include "push_swap.h"

t_stack	*parser(char **argv, intargc)
{
	int		i;
	t_stack	*new;
	t_stack	*stack;

	if (argc < 3)
		return (-1);
	i = 0;
	stack = NULL;
	while (i < argc)
	{
		check_valid_number(argv[i]);
		new = new_stack(ft_atoi(argv[i]));
		if (new == NULL)
			exit_msg("Error: Malloc");
		stack_add_back(&stack, new);
	}
	check_valid_stack(stack);
	check_sorted(stack);
	return (stack);
}

void	exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	check_valid_stack(t_stack *stack)
{
	t_stack	*tmp;

	while(stack)
	{
		tmp = stack->next;
		while(tmp)
		{
			if (stack->value == tmp->value)
				exit_msg("Error: Dublicate");
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	check_sorted(t_stack *stack)
{
	t_stack	*tmp;
	
	while(stack)
	{
		tmp = stack->next;
		while(tmp)
		{
			if (stack->value < tmp->value)
				tmp = tmp->next;
			else
				return;
		}
		stack = stack->next;
	}
	exit(0);
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
		if(!ft_isdigit((int)number[i]))
			exit_msg("Error: Invalid argument");
		i++;
	}
}
