/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:38 by mflavio-          #+#    #+#             */
/*   Updated: 2024/01/11 22:32:40 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = 0;
	if (!size || !count)
		return (malloc(0));
	if (size > 2147483647 / count)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	while (i < size * count)
		p[i++] = '\0';
	return (p);
}
