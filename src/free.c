/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:44:11 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/08 13:41:43 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_mutexes(t_data *academy)
{
	int	i;

	if (academy->alive)
	{
		pthread_mutex_destroy(academy->alive);
		free(academy->alive);
	}
	if (academy->print)
	{
		pthread_mutex_destroy(academy->print);
		free(academy->print);
	}
	i = 0;
	if (academy->forks)
	{
		while (i < academy->n_philos)
			pthread_mutex_destroy(&academy->forks[i++].fork);
		free(academy->forks);
	}
}

void	free_academy(t_data *academy)
{
	free_mutexes(academy);
	if (academy->philos)
		free(academy->philos);
	free(academy);
	academy->alive = NULL;
	academy->print = NULL;
	academy->forks = NULL;
	academy->philos = NULL;
	return ;
}

void	join_philos(t_data *academy)
{
	int	i;

	i = -1;
	while (++i < academy->n_philos)
		if (pthread_join(academy->philos[i].thread_id, NULL) != 0)
			error_and_exit("thread", academy);
}

static void	print_error(char *str)
{
	if (!ft_strcmp("input", str))
	{
		ft_putstr_fd("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
					number_of_times_each_philosopher_must_eat(optional)\n", 2);
	}
	if (!ft_strcmp("memory", str))
		ft_putstr_fd("Coudn't allocate memory\n", 2);
	if (!ft_strcmp("time", str))
		ft_putstr_fd("Time values should be greater than 60 ms\n", 2);
	if (!ft_strcmp("eat", str))
		ft_putstr_fd("Number of eating should be greater than 0\n", 2);
	if (!ft_strcmp("mutex", str))
		ft_putstr_fd("Mutex error\n", 2);
	if (!ft_strcmp("thread", str))
		ft_putstr_fd("Thread error\n", 2);
	if (!ft_strcmp("philo", str))
		ft_putstr_fd("Number of philos should be greater than 0\n", 2);
}

void	error_and_exit(char *str, t_data *academy)
{
	if (academy)
		free_academy(academy);
	print_error(str);
	exit (FAIL);
}
