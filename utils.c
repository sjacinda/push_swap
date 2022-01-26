#include "push_swap.h"

t_stack *find_last(t_stack *stack)
{
	while(stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
