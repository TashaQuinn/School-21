#include "push_swap.h"

void	do_operations2(t_elem **stack_a, t_elem **stack_b,
		t_elem *elem, int *ttype)
{
	if (*ttype == 4)
	{
		while (elem->b_score_rev-- > 0 && elem->a_score_rev--)
			do_rrr(stack_a, stack_b, 1);
		while (elem->a_score_rev-- > 0)
			do_rra(stack_a, 1);
	}
	if (*ttype == 5)
	{
		while (elem->b_score-- > 0)
			do_rb(stack_b, 1);
		while (elem->a_score_rev-- > 0)
			do_rra(stack_a, 1);
	}
	if (*ttype == 6)
	{
		while (elem->b_score_rev-- > 0)
			do_rrb(stack_b, 1);
		while (elem->a_score-- > 0)
			do_ra(stack_a, 1);
	}
}

void	final_sort(t_elem **stack)
{
	t_elem	*elem;
	int		min;
	int		max;
	int		i;
	int		size;

	if (find_minmaxmed(stack, &min, &max, &i) > 0)
		return ;
	elem = *stack;
	i = 0;
	while (elem->value != min)
	{
		elem = elem->next;
		i++;
	}
	size = stack_size(*stack);
	if (i <= size - i)
		while (i--)
			do_ra(stack, 1);
	else
		while (i++ < size)
			do_rra(stack, 1);
}

void	free_stack(t_elem **stack)
{
	t_elem	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		temp = NULL;
	}
}
