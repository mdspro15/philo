/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:04:14 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:19:48 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].id = i;
		philo[i].meals_eaten = 0;
		philo[i].left = (i + 1) % data->num_of_philo;
		philo[i].right = i;
		philo[i].last_meal_time = get_time();
		philo[i].data = data;
		i++;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->fork)
		ft_error("Memory is not allocated.\n");
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			ft_error("Mutex error.\n");
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL) != 0)
		ft_error("Mutex error.\n");
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		ft_error("Mutex error.\n");

}