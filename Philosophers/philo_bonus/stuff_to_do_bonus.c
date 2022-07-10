#include "philo_bonus.h"

void	eat(t_table *table)
{
	sem_wait(table->eat_sem);
	table->last_meal = timestamp_ms();
	if (table->n_meals > 0)
		table->n_meals--;
	sem_post(table->eat_sem);
	sem_wait(table->print_sem);
	printf("%07lli %d is eating\n", ms_has_passed(table), table->id);
	sem_post(table->print_sem);
	delay(table->to_eat);
}

void	sleep_n_think(t_table *table)
{
	sem_wait(table->print_sem);
	printf("%07lli %d is sleeping\n", ms_has_passed(table), table->id);
	sem_post(table->print_sem);
	delay(table->to_sleep);
	sem_wait(table->print_sem);
	printf("%07lli %d is thinking\n", ms_has_passed(table), table->id);
	sem_post(table->print_sem);
}
