#include "push_swap.h"

int	stack_size(t_elem *stack)
{
	if (!stack)
		return (0);
	else
		return (1 + stack_size(stack->next));
}

int	find_minmaxmed(t_elem **stack, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = stack_size(*stack);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	array = sort_array(array, size, *stack);
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	assign_ranks(*stack, array);
	free(array);
	return (0);
}

t_elem	*move_to_b(t_elem **stack)
{
	t_elem	*stack_b;
	int		min;
	int		max;
	int		med;
	int		size;

	if (find_minmaxmed(stack, &min, &max, &med) > 0)
		return (NULL);
	stack_b = NULL;
	size = stack_size(*stack);
	while (size > 3)
	{
		if ((*stack)->value == min || (*stack)->value == max
			|| (*stack)->value == med)
			do_ra(stack, 1);
		else
		{
			do_pb(stack, &stack_b, 1);
			size--;
		}
	}
	triple_sort(stack);
	return (stack_b);
}

int	is_sorted(t_elem *stack)
{
	t_elem	*elem;
	int		flag;

	flag = 0;
	elem = stack;
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value && flag)
			return (0);
		if (stack->value > stack->next->value)
			flag = 1;
		stack = stack->next;
	}
	if (stack && stack->value > elem->value && flag)
		return (0);
	return (1);
}

void	stack_sort(t_elem **stack)
{
	t_elem	*stack_b;

	if (is_sorted(*stack) == 0)
	{
		stack_b = move_to_b(stack);
		while (stack_b)
			move_to_a(stack, &stack_b);
	}
	final_sort(stack);
}
