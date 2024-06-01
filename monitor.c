/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:45:03 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:11:10 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo(t_philo *p);
int		is_philo_died(t_philo *p);

void	*monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->data->done)
		check_philo(p);
	return (NULL);
}

void	check_philo(t_philo *p)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < p->data->num_of_philo)
	{
		if (is_philo_died(&p[i]))
		{
			put_msg(DIED, p);
			p->data->is_dead = 1;
			p->data->done = 1;
		}
		if (p->data->time_must_eat > 0)
		{
			if (p[i].meals_eaten >= p->data->time_must_eat)
				count++;
		}
		i++;
	}
	if (count == p->data->num_of_philo)
	{
		put_msg(DONE, p);
		p->data->done = 1;
	}
}

int	is_philo_died(t_philo *p)
{
	if (get_time() - p->last_meal_time >= p->data->time_to_die)
		return (1);
	return (0);
}