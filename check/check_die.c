/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:23:04 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/27 19:01:18 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_die(void *philo)
{
	t_philo	*philosopher;
	
	philosopher = (t_philo *)philo;
	philosopher ->time_last_eat = get_time() - philosopher ->data->start_time;
	philosopher->time_of_death = get_time() - philosopher->time_last_eat - philosopher->data->start_time;
	if (philosopher ->data->time_to_die < philosopher ->time_of_death)
	{
		//printf("time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
		ft_message(philo, DIED);
		exit(0);
	}
	while (1)
	{
		if ((get_time() - philosopher->data->start_time) > philosopher->time_of_death)// se o tempo atual for maior do que o tempo que ele comeu
		{
			pthread_mutex_lock(&philosopher->data->write);
			printf("%d %d died\n", get_time() - philosopher->data->start_time, philosopher->id);
			pthread_mutex_unlock(&philosopher->data->life);
		}
		if (philosopher->data->i == philosopher->data->number_philo)
		{
			pthread_mutex_lock(&philosopher->data->write);
			printf("%d %d\n", get_time() - philosopher->data->start_time, philosopher->id);
			pthread_mutex_unlock(&philosopher->data->life);
		}
	}
	return (NULL);
}