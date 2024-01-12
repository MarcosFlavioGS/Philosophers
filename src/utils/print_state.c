/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:33:02 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:33:04 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && i < (n - 1))
	{
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}

void	print_state(t_philo *philo, char *state, time_t sim_start)
{
	const char	*str = "Philosopher";

	pthread_mutex_lock(&philo->args->state_lock);
	if (is_banquet_over(philo) && ft_strncmp(state, DIE, 5))
	{
		pthread_mutex_unlock(&philo->args->state_lock);
		return ;
	}
	printf("%ld %s %d %s\n",
		get_elapsed_time(sim_start), str, philo->id, state);
	pthread_mutex_unlock(&philo->args->state_lock);
}
