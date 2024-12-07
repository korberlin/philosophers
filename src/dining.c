/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:13:18 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/07 16:41:48 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alive_check(t_data *academy)
{
	pthread_mutex_lock(academy->alive);
	if (academy->any_dead == NO)
	{
		pthread_mutex_unlock(academy->alive);
		return (YES);
	}
	pthread_mutex_unlock(academy->alive);
	return (NO);
}

static int	take_forks(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		if (philo->total_eaten == 0)
			usleep(1000);
		pthread_mutex_lock(&philo->r_fork->fork);
		print_philo(philo, "fork");
		pthread_mutex_lock(&philo->l_fork->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork->fork);
		print_philo(philo, "fork");
		if (philo->academy->n_philos == 1)
		{
			while (alive_check(philo->academy))
				;
			pthread_mutex_unlock(&philo->l_fork->fork);
			return (NO);
		}
		pthread_mutex_lock(&philo->r_fork->fork);
	}
	print_philo(philo, "fork");
	return (YES);
}

static void	eating(t_philo *philo)
{
	while (alive_check(philo->academy))
	{
		if (philo->id == 1 && (philo->academy->n_philos % 2) != 0 \
			&& philo->total_eaten == 0)
			usleep(philo->academy->t_eat * 1000);
		if (take_forks(philo))
		{
			philo->last_meal = get_current_time();
			print_philo(philo, "eat");
			philo->total_eaten++;
			usleep(philo->academy->t_eat * 1000);
			pthread_mutex_unlock(&philo->l_fork->fork);
			pthread_mutex_unlock(&philo->r_fork->fork);
			break ;
		}
	}
}

void	dining(t_data *academy)
{
	int	i;

	create_philos(academy);
	i = 0;
	while (alive_check(academy))
	{
		while (i < academy->n_philos)
		{
			if (dead_check(&academy->philos[i]))
			{
				usleep(900);
				return (join_philos(academy));
			}
			if (all_eaten(academy))
			{
				usleep(900);
				return (join_philos(academy));
			}
			i++;
			i = i % academy->n_philos;
		}
	}
}

void	*begin_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (alive_check(philo->academy))
	{
		eating(philo);
		print_philo(philo, "sleep");
		usleep(philo->academy->t_sleep * 1000);
		print_philo(philo, "think");
		if (!(philo->academy->n_philos % 2))
			usleep(10);
		else
		{
			if ((philo->academy->t_die - philo->academy->t_eat \
				- philo->academy->t_sleep) <= 0)
				usleep(900);
			else
				usleep((philo->academy->t_die - philo->academy->t_eat \
					- philo->academy->t_sleep) * 900);
		}
	}
	return (0);
}
