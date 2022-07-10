#include "philo.h"

unsigned long long	timestamp_ms(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return (timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000);
}

unsigned long long	ms_has_passed(t_philo *philo)
{
	return (timestamp_ms() - philo->table->start);
}

#if __unix__

void	delay(int ms)
{
	usleep(ms * 1000);
}

#else

void	delay(int ms)
{
	unsigned long long	timestamp;

	timestamp = timestamp_ms();
	while (timestamp_ms() < timestamp + ms)
		;
}

#endif
