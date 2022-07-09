#include "push_swap.h"

int	two_more_ttypes(int result, t_elem *stack, int *ttype)
{
	if (stack->b_score + stack->a_score_rev < result)
	{
		result = stack->b_score + stack->a_score_rev;
		*ttype = 5;
	}
	if (stack->b_score_rev + stack->a_score < result)
	{
		result = stack->b_score_rev + stack->a_score;
		*ttype = 6;
	}
	return (result);
}

int	calculate_score(t_elem *stack, int *ttype)
{
	int	result;
	int	top_rscore;

	result = stack->b_score;
	*ttype = 1;
	if (stack->a_score >= stack->b_score)
	{
		result = stack->a_score;
		*ttype = 2;
	}
	top_rscore = stack->a_score_rev;
	if (stack->b_score_rev > top_rscore)
		top_rscore = stack->b_score_rev;
	if (result > top_rscore)
	{
		result = top_rscore;
		if (stack->b_score_rev > stack->a_score_rev)
			*ttype = 3;
		else
			*ttype = 4;
	}
	result = two_more_ttypes(result, stack, ttype);
	return (result);
}

t_elem	*pick_the_best(t_elem *stack, int *ttype)
{
	t_elem	*save;
	int		best_score;
	int		best_rank;
	int		best_ttype;

	best_score = calculate_score(stack, ttype);
	best_rank = stack->rank;
	best_ttype = *ttype;
	save = stack;
	while (stack)
	{
		if (calculate_score(stack, ttype) < best_score
			|| (calculate_score(stack, ttype) == best_score
				&& stack->rank >= best_rank))
		{
			best_score = calculate_score(stack, ttype);
			best_rank = stack->rank;
			best_ttype = *ttype;
		}
		stack = stack->next;
	}
	*ttype = best_ttype;
	while (save->rank != best_rank)
		save = save->next;
	return (save);
}

void	assign_ranks(t_elem *stack, int *array)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (array[i] != stack->value)
			i++;
		stack->rank = i;
		stack = stack->next;
	}
}

void	do_operations(t_elem **stack_a, t_elem **stack_b,
		t_elem *elem, int *ttype)
{
	if (*ttype == 1)
	{
		while (elem->a_score-- > 0 && elem->b_score--)
			do_rr(stack_a, stack_b, 1);
		while (elem->b_score-- > 0)
			do_rb(stack_b, 1);
	}
	if (*ttype == 2)
	{
		while (elem->b_score-- > 0 && elem->a_score--)
			do_rr(stack_a, stack_b, 1);
		while (elem->a_score-- > 0)
			do_ra(stack_a, 1);
	}
	if (*ttype == 3)
	{
		while (elem->a_score_rev-- > 0 && elem->b_score_rev--)
			do_rrr(stack_a, stack_b, 1);
		while (elem->b_score_rev-- > 0)
			do_rrb(stack_b, 1);
	}
	if (*ttype > 3)
		do_operations2(stack_a, stack_b, elem, ttype);
	do_pa(stack_a, stack_b, 1);
}
