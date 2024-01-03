#include "../../includes/philo.h"

void	increase_meals_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->meals_lock);
	philo->meals_done++;
	pthread_mutex_unlock(&philo->args->meals_lock);
}
