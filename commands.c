#include "push_swap.h"

void sa(t_stack **stack)
{
	t_stack		*first;
	t_stack		*second;
	t_stack		*third;

	if (stack == NULL)
		return;
	first = *stack;
	if (first == NULL)
		return;
	second = first->next;
	if (second == NULL)
		return;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
}

void sb(t_stack **stack)
{
	sa(stack);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (stack_a == NULL || stack_b == NULL)
		return;
	first_a = *stack_a;
	first_b = *stack_b;
	if (first_b == NULL)
		return;
	*stack_b = *stack_b->next;
	*stack_a = first_b;
	first_b->next = first_a;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	pa(stack_b, stack_a);
}

void ra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (stack == NULL)
		return;
	first = *stack;
	if (first == NULL)
		return;
	second = first->next;
	last = find_last(*stack);
	if (last == first)
		return;
	first->next = NULL;
	last->next = first;
	*stack = second;
}

void rb(t_stack **stack)
{
	ra(stack);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *pre_last;
	t_stack *last;

	if (stack == NULL)
		return;
	first = *stack;
	if (first == NULL)
		return;
	second = first->next;
	pre_last = find_pre_last(*stack);
	last = find_last(*stack);
	if (last == first)
		return;
	last->next = first;
	pre_last->next = NULL;
	*stack = last;
}

void rrb(t_stack **stack)
{
	rra(stack);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
