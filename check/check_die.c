/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:23:04 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/25 17:26:09 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_die(void *philo)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)philo;
	while (1)
	{
		if ((get_time() - philosophers->data->start_time) > philosophers->time_of_death)
		{
			pthread_mutex_lock(&philosophers->data->write);
			printf("%d %d", get_time() - philosophers->data->start_time, philosophers->id);
			pthread_mutex_unlock(&philosophers->data->life);
		}
		if (philosophers->data->i == philosophers->data->number_philo)
		{
			pthread_mutex_lock(&philosophers->data->write);
			printf("%d %d", get_time() - philosophers->data->start_time, philosophers->id);
			pthread_mutex_unlock(&philosophers->data->life);
		}
		usleep(500);
	}
	return (NULL);
}