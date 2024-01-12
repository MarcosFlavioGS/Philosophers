/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:30:27 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:30:47 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	free_forks(t_fork *forks, int quantity)
{
	int	index;

	index = 0;
	while (index < quantity)
	{
		pthread_mutex_destroy(&forks[index]);
		index++;
	}
	free(forks);
}

static void	free_locks(t_args *args)
{
	pthread_mutex_destroy(&args->state_lock);
	pthread_mutex_destroy(&args->meals_lock);
	pthread_mutex_destroy(&args->last_meal_lock);
	pthread_mutex_destroy(&args->banquet_lock);
}

void	free_table(t_table *table)
{
	free_forks(table->forks, table->philos->args->p_quantity);
	free_locks(table->philos->args);
	free(table->philos->args);
	free(table->philos);
	free(table);
}
