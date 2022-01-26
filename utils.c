#include "push_swap.h"

t_stack *find_last(t_stack *stack)
{
	while(stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack *find_pre_last(t_stack *stack)
{
	while(stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack *new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
}

void	stack_add_back(t_stack **stack, t_stack **new)
{
	t_stack	*last;

	if(stack == NULL)
		return;
	if(*stack == NULL)
	{
		*stack = new;
		return;
	}
	last = find_last(*stack);
	last->next new;
}
