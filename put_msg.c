/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:57:14 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:30:05 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_logo(int action, t_philo *p);

void	put_msg(int action, t_philo *p)
{
	long long	time;

	time = get_time() - p->data->start_time;
	if (p->data->is_dead || p->data->done)
		return ;
	pthread_mutex_lock(&p->data->write);
	printf("[%lldms]", time);
	put_logo(action, p);
	pthread_mutex_unlock(&p->data->write);
}

void	put_logo(int action, t_philo *p)
{
	if (action == DIED)
		printf("Philo %d has died\n", p->id + 1);
	else if (action == TAKE_LEFT)
		printf("Philo %d has taken fork %d\n", p->id + 1, p->left + 1);
	else if (action == TAKE_RIGHT)
		printf("Philo %d has taken fork %d\n", p->id + 1, p->right + 1);
	else if (action == EAT)
		printf("Philo %d is eating\n", p->id + 1);
	else if (action == PUT_LEFT)
		printf("Philo %d has released fork %d\n", p->id + 1, p->left + 1);
	else if (action == PUT_RIGHT)
		printf("Philo %d has released fork %d\n", p->id + 1, p->right + 1);
	else if (action == SLEEP)
		printf("Philo %d is sleeping\n", p->id + 1);
	else if (action == THINK)
		printf("Philo %d is thinking\n", p->id + 1);
	else if (action == DONE)
		printf("All philo has eaten %d times meal\n", p->meals_eaten);
}
