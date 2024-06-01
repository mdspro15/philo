/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:02:03 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:04:33 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	case_one(t_philo *p);

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->data->num_of_philo == 1)
	{
		case_one(p);
		return (NULL);
	}
	if (p->id % 2 == 0)
		msleep(p->data->time_to_sleep - 10);
	while (!p->data->done)
	{
		eat(p);
		sleeping(p);
		think(p);
	}
	return (NULL);
}

void	think(t_philo *p)
{
	put_msg(THINK, p);
}

void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->fork[p->left]);
	put_msg(TAKE_LEFT, p);
	pthread_mutex_lock(&p->data->fork[p->right]);
	put_msg(TAKE_RIGHT, p);
	put_msg(EAT, p);
	p->last_meal_time = get_time();
	p->meals_eaten++;
	msleep(p->data->time_to_eat);
	pthread_mutex_unlock(&p->data->fork[p->left]);
	put_msg(PUT_LEFT, p);
	pthread_mutex_unlock(&p->data->fork[p->right]);
	put_msg(PUT_RIGHT, p);
}

void	sleeping(t_philo *p)
{
	put_msg(SLEEP, p);
	msleep(p->data->time_to_sleep);
}

void	case_one(t_philo *p)
{
	pthread_mutex_lock(&p->data->fork[p->left]);
	put_msg(TAKE_LEFT, p);
	msleep(p->data->time_to_die);
	p->data->is_dead = 1;
	p->data->done = 1;
	return ;
}