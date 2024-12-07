/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:36:13 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/08 11:57:03 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000LL) + (time.tv_usec / 1000LL);
	return (ms);
}

int	dead_check(t_philo *philo)
{
	if ((get_current_time() - philo->last_meal) > philo->academy->t_die)
	{
		print_philo(philo, "dead");
		pthread_mutex_lock(philo->academy->alive);
		philo->academy->any_dead = YES;
		pthread_mutex_unlock(philo->academy->alive);
		return (YES);
	}
	return (NO);
}

void	print_philo(t_philo *philo, char *str)
{
	long long	timer;

	timer = get_current_time() - philo->academy->begin_time;
	if (!alive_check(philo->academy))
		return ;
	pthread_mutex_lock(philo->academy->print);
	if (!ft_strcmp("sleep", str))
		printf("%lld %i is sleeping\n", timer, philo->id);
	else if (!ft_strcmp("fork", str))
		printf("%lld %i has taken a fork\n", timer, philo->id);
	else if (!ft_strcmp("eat", str))
		printf("%lld %i is eating\n", timer, philo->id);
	else if (!ft_strcmp("think", str))
		printf("%lld %i is thinking\n", timer, philo->id);
	else
		printf("%lld %i died\n", timer, philo->id);
	pthread_mutex_unlock(philo->academy->print);
}

int	all_eaten(t_data *academy)
{
	int	i;

	if (academy->n_must_eat < 0)
		return (NO);
	i = 0;
	while (i < academy->n_philos)
	{
		if (academy->philos[i].total_eaten < academy->n_must_eat)
			return (NO);
		i++;
	}
	academy->any_dead = YES;
	return (YES);
}

void	create_philos(t_data *academy)
{
	int	i;

	i = 0;
	while (i < academy->n_philos)
	{
		academy->philos[i].thread_id = 0;
		if (pthread_create(&academy->philos[i].thread_id, NULL, \
			begin_philo, &academy->philos[i]) != 0)
			error_and_exit("thread", academy);
		usleep(1);
		i++;
	}
}
