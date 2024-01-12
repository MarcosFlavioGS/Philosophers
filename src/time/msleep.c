/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:09 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:32:10 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	msleep(int time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < (long)time)
		usleep(10);
}
