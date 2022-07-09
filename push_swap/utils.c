#include "push_swap.h"

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

t_elem	*new_elem(int value)
{
	t_elem	*elem;

	elem = (t_elem *)malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->a_score = -1;
	elem->a_score_rev = -1;
	elem->b_score = -1;
	elem->b_score_rev = -1;
	elem->rank = -1;
	elem->next = NULL;
	return (elem);
}

t_elem	*find_last(t_elem *elem)
{
	if (!elem)
		return (NULL);
	if (!(elem->next))
		return (elem);
	else
		return (find_last(elem->next));
}

void	add_back(t_elem **stack, t_elem *new)
{
	t_elem	*elem;

	if (!(*stack))
		*stack = new;
	else
	{
		elem = find_last(*stack);
		elem->next = new;
	}
}

t_elem	*stack_init(char **argv, int argc, int flag)
{
	t_elem	*elem;
	int		i;

	i = 1;
	elem = NULL;
	while (i < argc + flag)
	{
		add_back(&elem, new_elem(ft_atoi(argv[i - flag])));
		i++;
	}
	return (elem);
}
