/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:31:42 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:31:43 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	msleep(philo->args->p_sleep);
	return (1);
}
