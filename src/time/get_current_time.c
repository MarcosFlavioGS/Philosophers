#include "../../includes/philo.h"

time_t	get_current_time(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}
