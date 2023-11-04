/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:48 by mflavio-          #+#    #+#             */
/*   Updated: 2023/10/26 17:10:50 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void *routine()
{
	printf("Test from threads\n");
	return (0);
}

/*
** Entrypoint of the Philosophers program.
*/
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t philo_array[5];
	int num;
	int i;

	i = 0;
	num = 5;
	while (i < num)
	{
		if (pthread_create(&philo_array[i], NULL, &routine, NULL) != 0)
		{
			return (1);
		}
		printf("Philosopher %d created\n", i);
		i++;
	}
	i = 0;
	while (i < num - 1)
	{
		if (pthread_join(philo_array[i], NULL) != 0)
		{
			return (2);
		}
		i++;
	}
	return (0);
}
