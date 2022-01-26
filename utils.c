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