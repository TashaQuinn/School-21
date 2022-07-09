#include "push_swap.h"

void	do_ra(t_elem **stack, int flag)
{
	t_elem	*temp;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		add_back(stack, temp);
		if (flag)
			ft_putstr_fd("ra\n", 1);
	}
}

void	do_pb(t_elem **stack_a, t_elem **stack_b, int flag)
{
	t_elem	*elem1;
	t_elem	*elem2;

	if (*stack_a)
	{
		elem1 = *stack_b;
		elem2 = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = elem2;
		(*stack_b)->next = elem1;
		if (flag)
			ft_putstr_fd("pb\n", 1);
	}
}

void	do_sa(t_elem **stack, int flag)
{
	t_elem	*elem1;
	t_elem	*elem2;

	elem1 = *stack;
	if (*stack && (*stack)->next)
	{
		elem2 = (*stack)->next;
		(*stack)->next = elem2->next;
		elem2->next = elem1;
		*stack = elem2;
		if (flag)
			ft_putstr_fd("sa\n", 1);
	}
}

void	do_pa(t_elem **stack_a, t_elem **stack_b, int flag)
{
	t_elem	*elem1;
	t_elem	*elem2;

	if (*stack_b)
	{
		elem1 = *stack_a;
		elem2 = *stack_b;
		*stack_b = (*stack_b)->next;
		*stack_a = elem2;
		(*stack_a)->next = elem1;
		if (flag)
			ft_putstr_fd("pa\n", 1);
	}
}

void	do_rb(t_elem **stack, int flag)
{
	t_elem	*temp;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		add_back(stack, temp);
		if (flag)
			ft_putstr_fd("rb\n", 1);
	}
}
