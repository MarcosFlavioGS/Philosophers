/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:32 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:32:35 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long int	ft_atoi(const char *str)
{
	int			neg_counter;
	long int	final_num;

	neg_counter = 0;
	final_num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\f' || *str == '\v')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			neg_counter = 1;
		str++;
	}
	while (48 <= *str && *str <= 57)
	{
		final_num = (*str - 48) + (final_num * 10);
		str++;
	}
	if (neg_counter == 1)
		return (final_num * -1);
	else
		return (final_num);
}
