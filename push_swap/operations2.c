#include "push_swap.h"

void	rr_output(int op_type)
{
	if (op_type == 1)
		ft_putstr_fd("ra\n", 1);
	if (op_type == 2)
		ft_putstr_fd("rb\n", 1);
	if (op_type == 3)
		ft_putstr_fd("rr\n", 1);
}

void	do_rr(t_elem **stack_a, t_elem **stack_b, int flag)
{
	t_elem	*temp;
	int		op_type;

	op_type = 0;
	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		add_back(stack_a, temp);
		op_type += 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		add_back(stack_b, temp);
		op_type += 2;
	}
	if (flag)
		rr_output(op_type);
}

t_elem	*find_before_last(t_elem *stack)
{
	if (!stack)
		return (NULL);
	if (!(stack->next))
		return (NULL);
	if (!(stack->next->next))
		return (stack);
	else
		return (find_before_last(stack->next));
}

void	add_front(t_elem **stack, t_elem *elem)
{
	elem->next = *stack;
	*stack = elem;
}

void	do_rra(t_elem **stack, int flag)
{
	t_elem	*before_last;

	if (*stack && (*stack)->next)
	{
		before_last = find_before_last(*stack);
		add_front(stack, before_last->next);
		before_last->next = NULL;
		if (flag)
			ft_putstr_fd("rra\n", 1);
	}
}
