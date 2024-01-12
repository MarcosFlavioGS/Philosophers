/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:31:12 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:31:22 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void *eat_alone(t_philo *philo, time_t sim_start)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, TAKE_FORK, sim_start);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void *simulation(void *ptr)
{
	t_philo *philo;

	philo = ptr;
	if (philo->id % 2 == 0)
		msleep(5);
	if (philo->args->p_quantity == 1)
		return (eat_alone(philo, philo->sim_start));
	while (!is_banquet_over(philo))
	{
		eat(philo, philo->sim_start);
		if (philo->meals_done == philo->args->p_eat_quantity)
			return (NULL);
		rest(philo, philo->sim_start);
		think(philo, philo->sim_start);
	}
	return (NULL);
}
