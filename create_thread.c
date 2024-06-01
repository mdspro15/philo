/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:11:42 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 16:05:52 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//create monitor thread and philo thread

int	create_thread(t_data *data, t_philo *philo)
{
	int			i;
	pthread_t	checker;

	i = 0;
	data->start_time = get_time();
	if (pthread_create(&checker, NULL, &monitor, philo) != 0)
		ft_error("Thread cannot be created!\n");
	while (i < data->num_of_philo)
	{
		if (pthread_create(&philo[i].th, NULL, &routine, &philo[i]) != 0)
			ft_error("Thread cannot be created!\n");
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			ft_error("Thread cannot be joined!\n");
		i++;
	}
	return (0);
}
