/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:57:04 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:28:45 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(t_data *d, t_philo *p);

int	main(int ac, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (check_arg(ac, argv))
		return (1);
	save_data(&data, ac, argv)
	philo = (t_philo *)malloc(sizeof(t_philo) * data.num_of_philo);
	if (!philo)
		return (1);
	if (run_simulation(&data, philo))
		return (1);
	return (0);
}

int	run_simulation(t_data *d, t_philo *p)
{
	init_philo(d, p);
	if (init_mutex(d))
		return (1);
	if (create_thread(d, p))
		return (1);
	destroy_all(d);
	free(p);
	free(d->fork);
	return (0);
}