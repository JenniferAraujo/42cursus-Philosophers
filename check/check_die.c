/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:23:04 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/01 22:05:49 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_die(void *philo)
{
	t_philo	*philosopher;
	int	i = 0;
	int time_of_death;
	
	philosopher = (t_philo *)philo;
	while (1)
	{	
		i = 0;
		while (i < philosopher->data->number_philo)
		{
			pthread_mutex_lock(&(philosopher)->data->eat);
			time_of_death = get_time() - philosopher->data->start_time - philosopher[i].time_last_eat;
			pthread_mutex_unlock(&(philosopher)->data->eat);
			if (time_of_death > philosopher->data->time_to_die)// se o tempo entre refeicoes for maior que o tempo para morrer
			{
				set_mutex(&philosopher->data->death, 1, &philosopher->data->end);
				//usleep(1);
				pthread_mutex_lock(&philosopher->data->write);
				printf("%d %d \033[31mdied\n\033[0m", get_time() - philosopher->data->start_time, philosopher[i].id);
				pthread_mutex_unlock(&philosopher->data->write);
			
				return (NULL);
			}
			if (philosopher->data->i == philosopher->data->number_philo)
				set_mutex(&philosopher->data->meals, 1, &philosopher->data->end);
			i++;
			
		}
	}
	return (NULL);
}
