/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:23:04 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 20:42:41 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_die(void *philo)
{
	t_philo	*philosopher;
	
	philosopher = (t_philo *)philo;
	philosopher->time_last_eat = get_time() - philosopher ->data->start_time;
	pthread_mutex_lock(&(philosopher)->data->eat);
	philosopher->time_of_death = get_time() - philosopher->time_last_eat - philosopher->data->start_time + philosopher->data->time_to_die;
	pthread_mutex_unlock(&(philosopher)->data->eat);
	while (1)
	{
		pthread_mutex_lock(&(philosopher)->data->eat);
		if ((get_time() - philosopher->data->start_time) > philosopher->time_of_death)// se o tempo atual for maior do que o tempo que ele comeu
		{
			pthread_mutex_lock(&philosopher->data->write);
			printf("%d %d \033[31mdied\n\033[0m", get_time() - philosopher->data->start_time, philosopher->id);
			pthread_mutex_unlock(&philosopher->data->write);
			pthread_mutex_unlock(&philosopher->data->dead);
		}
		pthread_mutex_unlock(&(philosopher)->data->eat);
		if (philosopher->data->i == philosopher->data->number_philo)
		{
			pthread_mutex_lock(&philosopher->data->write);
			printf("%d %d\n", get_time() - philosopher->data->start_time, philosopher->id);
			pthread_mutex_unlock(&philosopher->data->write);
			pthread_mutex_unlock(&philosopher->data->dead);
		}
	}
	return (NULL);
}
