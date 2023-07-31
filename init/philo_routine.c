/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:31:49 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 19:12:13 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_table(t_philo	*philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		ft_take_fork_left(philo);
	else
	{
		if (philosopher->data->number_philo % 2 != 0)
			if (philosopher->data->time_dif > 0)
				ft_usleep(philosopher->data->time_dif);
		ft_take_fork_right(philo);
	}
	ft_eat(philo);
	ft_drop_forks(philo);
}

void	*philo_routine(void *philo)
{
	t_philo		*philosopher;
	pthread_t	pthread_id;

	philosopher = (t_philo *)philo;
	pthread_create(&pthread_id, NULL, (void *)check_die, philo);
	if (philosopher->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		philo_table(philo);
		ft_sleep(philo);
		ft_thinking(philo);
		if (philosopher->eat_number == philosopher->data->number_meals)
			philosopher->data->i++;
		if (philosopher->data->i == philosopher->data->number_philo)
			break ;
	}
	return (NULL);
}
