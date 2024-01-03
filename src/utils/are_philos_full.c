#include "../../includes/philo.h"

static int	get_meals_done(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->args->meals_lock);
	meals_done = philo->meals_done;
	pthread_mutex_unlock(&philo->args->meals_lock);
	return (meals_done);
}

int	are_philos_full(t_philo *philos)
{
	int	i;
	int	ate;

	ate = 0;
	i = 0;
	while (i < philos->args->p_quantity)
	{
		if (get_meals_done(&philos[i]) == philos->args->p_eat_quantity)
			ate++;
		i++;
	}
	if (ate == philos->args->p_quantity)
		return (1);
	return (0);
}
