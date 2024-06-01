/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:20:12 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 16:01:10 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//gettimeofday returns time in seconds and microseconds since 1970
//get_time() return current time in milliseconds
//1 second = 1000 milliseconds
//1 millisecond = 1000 microseconds

long long	get_time(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_in_ms);
}

//In order to sleep in milliseconds using usleep()
//You will have to multiply input by 1000 but this way is not precise
//So you will need to write your own sleep function
void	msleep(long long ms)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
}
