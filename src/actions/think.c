/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:31:47 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:31:53 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
	return (1);
}
