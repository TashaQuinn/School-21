#include "push_swap.h"

int	any_duplicates(char **argv, int argc, int flag)
{
	int	*array;
	int	i;
	int	j;
	int	dup;

	dup = 0;
	array = (int *)malloc(sizeof(int) * (argc - 1 + flag));
	if (!array)
		return (1);
	i = -1;
	while (++i < argc - 1 + flag)
		array[i] = ft_atoi(argv[i + 1 - flag]);
	i = -1;
	while (++i < argc - 2 + flag)
	{
		j = i;
		while (++j < argc - 1 + flag)
			if (array[i] == array[j])
				dup = 1;
	}
	free(array);
	return (dup);
}

int	outside_limits(char *argv)
{
	long long int	nbr;

	nbr = ft_atoi(argv);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}

int	any_non_digits(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[i] && ft_is_space(argv[i]))
		i++;
	if (argv[i] && (argv[i] == '-' || argv[i] == '+'))
	{
		i++;
		flag = 1;
	}
	while (argv[i])
	{
		if (ft_is_digit(argv[i]) != 1)
			return (1);
		i++;
	}
	if (flag && i == 1)
		return (1);
	return (0);
}

int	are_args_valid(char **argv, int argc, int flag)
{
	int	i;
	int	error;

	i = 1;
	while (i < argc + flag)
	{
		error = any_non_digits(argv[i - flag]);
		if (error > 0)
			return (error);
		error = outside_limits(argv[i - flag]);
		if (error > 0)
			return (error);
		i++;
	}
	error = any_duplicates(argv, argc, flag);
	if (error > 0)
		return (error);
	return (0);
}
