/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_banquet_over.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:55 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:32:56 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_banquet_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->args->banquet_lock);
	end = 0;
	if (philo->args->banquet_ended)
		end = 1;
	pthread_mutex_unlock(&philo->args->banquet_lock);
	return (end);
}
