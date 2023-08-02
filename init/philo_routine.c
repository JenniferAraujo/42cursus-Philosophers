/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:31:49 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:22:56 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_table(t_philo	*philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philo->data->number_philo == 1)
	{
		one_philo(philo);
		return ;
	}
	if (philosopher->id % 2 == 0)
		ft_take_fork_left(philo);
	else
	{
		if (philosopher->data->number_philo % 2 != 0)
		{
			if (philosopher->data->time_dif > 0)
				ft_usleep(philosopher->data->time_dif);
		}
		ft_take_fork_right(philo);
	}
	ft_eat(philo);
	ft_drop_forks(philo);
}

void	*philo_routine(void *philo)
{
	t_philo		*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		pthread_mutex_lock(&(philosopher)->data->end);
		if (philosopher->data->death == 1 || philosopher->data->meals == 1)
		{
			pthread_mutex_unlock(&(philosopher)->data->end);
			return (NULL);
		}
		else
			pthread_mutex_unlock(&(philosopher)->data->end);
		philo_table(philo);
		ft_sleep(philo);
		ft_thinking(philo);
		check_full(philo);
	}
	return (NULL);
}
