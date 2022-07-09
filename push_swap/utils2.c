#include "push_swap.h"

int	*sort_array(int *array, int size, t_elem *stack)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}

void	triple_sort(t_elem **stack)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = stack_size(*stack);
	if (size == 3)
	{
		first = (*stack)->value;
		second = (*stack)->next->value;
		third = (*stack)->next->next->value;
		if (second > third && second > first && third > first)
			do_sa(stack, 1);
		if (third > first && third > second && first > second)
			do_sa(stack, 1);
		if (first > third && first > second && second > third)
			do_sa(stack, 1);
	}
}

void	a_score_elem(t_elem *stack_a, t_elem *stack_b)
{
	t_elem	*save;
	int		size;
	int		i;
	int		pr_val;

	size = stack_size(stack_a);
	save = stack_a;
	while (stack_b)
	{
		stack_a = save;
		i = 0;
		pr_val = find_last(stack_a)->value;
		while (stack_a)
		{
			if (pr_val < stack_b->value && stack_a->value > stack_b->value)
			{
				stack_b->a_score = i;
				stack_b->a_score_rev = size - i;
			}
			i++;
			pr_val = stack_a->value;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

void	b_score_elem(t_elem *stack_b)
{
	int	size;
	int	i;

	size = stack_size(stack_b);
	i = 0;
	while (stack_b)
	{
		stack_b->b_score = i;
		stack_b->b_score_rev = size - i;
		i++;
		stack_b = stack_b->next;
	}
}

void	move_to_a(t_elem **stack_a, t_elem **stack_b)
{
	t_elem	*winner;
	int		ttype;

	b_score_elem(*stack_b);
	a_score_elem(*stack_a, *stack_b);
	winner = pick_the_best(*stack_b, &ttype);
	do_operations(stack_a, stack_b, winner, &ttype);
}
