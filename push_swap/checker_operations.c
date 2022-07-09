#include "push_swap.h"

void	do_sb(t_elem **stack, int flag)
{
	t_elem	*elem1;
	t_elem	*elem2;

	elem1 = *stack;
	if (*stack && (*stack)->next)
	{
		elem2 = (*stack)->next;
		(*stack)->next = elem2->next;
		elem2->next = elem1;
		(*stack) = elem2;
		if (flag)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss_output(int op_type)
{
	if (op_type == 1)
		ft_putstr_fd("sa\n", 1);
	if (op_type == 2)
		ft_putstr_fd("sb\n", 1);
	if (op_type == 3)
		ft_putstr_fd("ss\n", 1);
}

void	do_ss(t_elem **stack_a, t_elem **stack_b, int flag)
{
	t_elem	*elem1;
	t_elem	*elem2;
	int		op_type;

	op_type = 0;
	elem1 = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		elem2 = (*stack_a)->next;
		(*stack_a)->next = elem2->next;
		elem2->next = elem1;
		(*stack_a) = elem2;
		flag += 1;
	}
	elem1 = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		elem2 = (*stack_b)->next;
		(*stack_b)->next = elem2->next;
		elem2->next = elem1;
		(*stack_b) = elem2;
		flag += 2;
	}
	if (flag)
		ss_output(op_type);
}
