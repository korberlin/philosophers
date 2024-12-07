/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:56:36 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/08 13:41:58 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAIL 1
# define NO 0
# define YES 1

typedef struct s_academy	t_academy;

typedef struct s_fork {
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo {
	int			id;
	pthread_t	thread_id;
	int			total_eaten;
	int			eaten;
	long long	last_meal;
	t_fork		*l_fork;
	t_fork		*r_fork;
	t_academy	*academy;
}	t_philo;

typedef struct s_academy {
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_must_eat;
	int				any_dead;
	pthread_mutex_t	*alive;
	long long		begin_time;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	*print;
}	t_data;

void		init_academy(t_data *academy, char **argv, int argc);
void		dining(t_data *academy);
void		error_and_exit(char *str, t_data *academy);
long long	get_current_time(void);
void		free_academy(t_data *academy);
void		print_philo(t_philo *philo, char *str);
void		*begin_philo(void *void_philo);
void		create_philos(t_data *academy);
int			alive_check(t_data *academy);
int			dead_check(t_philo *philo);
void		join_philos(t_data *academy);
int			all_eaten(t_data *academy);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
#endif
