/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:56:30 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 17:26:21 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# define DIED 0
# define TAKE_LEFT 1
# define TAKE_RIGHT 2
# define EAT 3
# define PUT_LEFT 4
# define PUT_RIGHT 5
# define SLEEP 6
# define THINK 7
# define DONE 8

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				done;
	int				is_dead;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	int			left;
	int			right;
	long long	last_meal_time;
	pthread_t	th;
	t_data		*data;
}	t_philo;

int			check_arg(int ac, char **argv);
void		save_data(t_data *data, int ac, char **argv);
void		init_philo(t_data *data, t_philo *philo);
int			init_mutex(t_data *data);
int			create_thread(t_data *data, t_philo *philo);
void		*routine(void *arg);
void		*monitor(void *arg);
void		think(t_philo *p);
void		eat(t_philo *p);
void		sleeping(t_philo *p);
long long	get_time(void);
void		msleep(long long ms);
void		put_msg(int action, t_philo *p);
int			ft_error(char *msg);
void		destroy_all(t_data *d);

#endif
