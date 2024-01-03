#include "../../includes/philo.h"

void	msleep(int time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < (long)time)
		usleep(10);
}
