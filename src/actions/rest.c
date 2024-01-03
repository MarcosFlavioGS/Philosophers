#include "../../includes/philo.h"

int	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	msleep(philo->args->p_sleep);
	return (1);
}
