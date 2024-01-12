/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_meals_done.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:49 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:32:51 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	increase_meals_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->meals_lock);
	philo->meals_done++;
	pthread_mutex_unlock(&philo->args->meals_lock);
}
