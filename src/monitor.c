/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:31:04 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:31:07 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->args->last_meal_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->args->last_meal_lock);
	return (last_meal);
}

static void	end_banquet(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->banquet_lock);
	philo->args->banquet_ended = 1;
	pthread_mutex_unlock(&philo->args->banquet_lock);
}

void	*monitor(void *arg)
{
	long			timenow;
	t_philo			*philos;
	int				i;

	i = 0;
	philos = (t_philo *)arg;
	while (!are_philos_full(philos))
	{
		i = 0;
		while (i < philos->args->p_quantity)
		{
			timenow = get_elapsed_time(philos->sim_start);
			if (timenow - get_last_meal(&philos[i]) > philos->args->p_die)
			{
				end_banquet(&philos[i]);
				print_state(&philos[i], DIE, philos[i].sim_start);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
