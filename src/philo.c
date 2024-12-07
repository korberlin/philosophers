/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:19:54 by gkoksal           #+#    #+#             */
/*   Updated: 2024/08/07 16:20:58 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (!((argc == 5) || (argc == 6)))
		return (FAIL);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*academy;

	if (validate_input(argc, argv) == FAIL)
		error_and_exit("input", NULL);
	academy = ft_calloc(1, sizeof(t_data));
	if (!academy)
		error_and_exit("memory", NULL);
	if (argc == 6)
		init_academy(academy, argv, 6);
	else
		init_academy(academy, argv, 5);
	dining(academy);
	free_academy(academy);
	return (0);
}
