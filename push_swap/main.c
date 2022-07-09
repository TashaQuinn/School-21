#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*stack_a;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = splited_argc(argv);
		flag = 1;
	}
	if ((are_args_valid(argv, argc, flag) > 0))
	{
		ft_putstr_fd("Error\n", 2);
		if (flag)
			free_array(argv);
		exit(EXIT_FAILURE);
	}
	if (argc > 1)
	{
		stack_a = stack_init(argv, argc, flag);
		stack_sort(&stack_a);
		free_stack(&stack_a);
	}
	if (flag)
		free_array(argv);
}
