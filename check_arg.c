/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:06:17 by schiou            #+#    #+#             */
/*   Updated: 2024/02/25 15:58:50 by schiou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c);
int	is_only_zero(char *str);

int	check_arg(int ac, char **argv)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		ft_error("Error:Please pass 4 or 5 arugments!\n");
	i = 1;
	while (i < ac)
	{
		if (is_only_zero(argv[i]))
			ft_error("Error:Non valid number!\n");
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("Error:Please pass only number!\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_only_zero(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '0')
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
