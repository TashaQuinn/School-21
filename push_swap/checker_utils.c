#include "push_swap.h"

int	is_ok_sorted(t_elem *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	do_op(t_elem **stack_a, t_elem **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		do_sa(stack_a, 0);
	else if (ft_strcmp(op, "sb") == 0)
		do_sb(stack_b, 0);
	else if (ft_strcmp(op, "ss") == 0)
		do_ss(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "pa") == 0)
		do_pa(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "pb") == 0)
		do_pb(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "ra") == 0)
		do_ra(stack_a, 0);
	else if (ft_strcmp(op, "rb") == 0)
		do_rb(stack_b, 0);
	else if (ft_strcmp(op, "rr") == 0)
		do_rr(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "rra") == 0)
		do_rra(stack_a, 0);
	else if (ft_strcmp(op, "rrb") == 0)
		do_rrb(stack_b, 0);
	else if (ft_strcmp(op, "rrr") == 0)
		do_rrr(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

char	**read_operations(void)
{
	char	*op;
	char	**operations;
	int		i;

	i = 0;
	operations = malloc(sizeof(char *) * 10000);
	op = get_next_line(0);
	while (op[0] != '\0')
	{
		operations[i++] = op;
		op = get_next_line(0);
	}
	free(op);
	operations[i] = NULL;
	return (operations);
}

void	check_instructions(t_elem **stack_a)
{
	t_elem	*stack_b;
	char	**instructions;
	int		i;

	instructions = read_operations();
	i = 0;
	stack_b = NULL;
	while (instructions[i])
	{
		if (do_op(stack_a, &stack_b, instructions[i++]) != 0)
		{
			free_stack(&stack_b);
			free_array(instructions);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
	}
	if (is_ok_sorted(*stack_a) == 0 || stack_size(stack_b) > 0)
	{
		ft_putstr_fd("KO\n", 1);
		free_stack(&stack_b);
	}
	else
		ft_putstr_fd("OK\n", 1);
	free_array(instructions);
}
