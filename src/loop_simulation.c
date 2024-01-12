/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:30:51 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:30:55 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void loop_simulation(t_table *table)
{
	pthread_t *threads;
	pthread_t monitor_thread;
	int       i;

	threads = ft_calloc(sizeof(pthread_t), table->philos->args->p_quantity);
	i = 0;
	while (i < table->philos->args->p_quantity)
	{
		pthread_create(&threads[i], NULL, simulation, &table->philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitor_thread, NULL, monitor, table->philos);
	while (i < table->philos->args->p_quantity)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	free(threads);
}
