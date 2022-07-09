#include "push_swap.h"

void	do_rrb(t_elem **stack, int flag)
{
	t_elem	*before_last;

	if (*stack && (*stack)->next)
	{
		before_last = find_before_last(*stack);
		add_front(stack, before_last->next);
		before_last->next = NULL;
		if (flag)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	do_rrr(t_elem **stack_a, t_elem **stack_b, int flag)
{
	t_elem	*before_last;
	int		op_type;

	op_type = 0;
	if (*stack_a && (*stack_a)->next)
	{
		before_last = find_before_last(*stack_a);
		add_front(stack_a, before_last->next);
		before_last->next = NULL;
		op_type += 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		before_last = find_before_last(*stack_b);
		add_front(stack_b, before_last->next);
		before_last->next = NULL;
		op_type += 2;
	}
	if (op_type == 1 && flag)
		ft_putstr_fd("rra\n", 1);
	if (op_type == 2 && flag)
		ft_putstr_fd("rrb\n", 1);
	if (op_type == 3 && flag)
		ft_putstr_fd("rrr\n", 1);
}
