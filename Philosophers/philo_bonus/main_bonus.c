#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table		*table;

	if (check_input(argc, argv) == 1)
		exit(1);
	table = NULL;
	init_struct(&table, argv);
	start_threads(ft_atoi(argv[1]), table);
	if (sem_wait(table->dead_sem) != 0)
	{
		free_struct(table, ft_atoi(argv[1]));
		exit(1);
	}
	free_struct(table, ft_atoi(argv[1]));
	return (0);
}

void	free_struct(t_table *table, int n_philos)
{
	int	j;

	j = 0;
	while (j < n_philos)
		kill(table->pids[j++], SIGKILL);
	j = 0;
	sem_unlink("eat_sem");
	sem_unlink("print_sem");
	sem_unlink("dead_sem");
	sem_unlink("forks");
	sem_close(table->eat_sem);
	sem_close(table->print_sem);
	sem_close(table->dead_sem);
	sem_close(table->forks);
	free(table->pids);
	free(table);
}
