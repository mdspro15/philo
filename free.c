/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:58:29 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:22:20 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	return(1);
}

void	destroy_all(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->num_of_philo)
	{
		pthread_mutex_destroy(&d->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&d->write);
}
