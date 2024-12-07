/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:56:01 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/08 13:52:11 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_data *academy)
{
	int		i;
	t_fork	*forks;

	forks = academy->forks;
	i = -1;
	while (++i < academy->n_philos)
	{
		forks[i].id = i + 1;
		if (pthread_mutex_init(&forks[i].fork, NULL) != 0)
			error_and_exit("mutex", academy);
	}
}

static void	init_philos(t_data *academy)
{
	int	i;

	i = -1;
	while (++i < academy->n_philos)
	{
		academy->philos[i].id = i + 1;
		academy->philos[i].last_meal = get_current_time();
		academy->philos[i].total_eaten = 0;
		academy->philos[i].eaten = NO;
		academy->philos[i].l_fork = &academy->forks[i];
		academy->philos[i].r_fork = &academy->forks[(i + 1) % \
		academy->n_philos];
		academy->philos[i].academy = academy;
	}
}

static void	init_mutexes(t_data *academy)
{
	academy->print = malloc(sizeof(pthread_mutex_t));
	if (!academy->print)
		error_and_exit("memory", academy);
	if (pthread_mutex_init(academy->print, NULL) != 0)
	{
		free(academy->print);
		academy->print = NULL;
		error_and_exit("mutex", academy);
	}
	academy->alive = malloc(sizeof(pthread_mutex_t));
	if (!academy->alive)
		error_and_exit("memory", academy);
	if (pthread_mutex_init(academy->alive, NULL) != 0)
	{
		free(academy->alive);
		academy->alive = NULL;
		error_and_exit("mutex", academy);
	}
}

void	init_academy(t_data *academy, char **argv, int argc)
{
	academy->n_philos = ft_atoi(argv[1]);
	if (academy->n_philos <= 0)
		error_and_exit("philo", academy);
	academy->t_die = ft_atoi(argv[2]);
	academy->t_eat = ft_atoi(argv[3]);
	academy->t_sleep = ft_atoi(argv[4]);
	academy->n_must_eat = -1;
	if (argc == 6)
		academy->n_must_eat = ft_atoi(argv[5]);
	if (academy->t_die < 60 || academy->t_eat < 60
		|| academy->t_sleep < 60)
		error_and_exit("time", academy);
	if (!academy->n_must_eat)
		error_and_exit("eat", academy);
	academy->any_dead = NO;
	academy->begin_time = get_current_time();
	academy->philos = ft_calloc((academy->n_philos), sizeof(t_philo));
	academy->forks = ft_calloc((academy->n_philos), sizeof(t_fork));
	if (!academy->philos || !academy->forks)
		error_and_exit("memory", academy);
	init_forks(academy);
	init_philos(academy);
	init_mutexes(academy);
}
