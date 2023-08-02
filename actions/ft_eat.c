/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 18:34:16 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_eat(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	ft_message(philo, EATING);
	pthread_mutex_lock(&(philosopher)->data->eat);
	philosopher->time_last_eat = get_time() - philosopher->data->start_time;
	pthread_mutex_unlock(&(philosopher)->data->eat);
	ft_usleep(philosopher->data->time_to_eat);
	pthread_mutex_lock(&(philosopher)->data->full);
	if (philosopher->data->number_meals != -1)
		philosopher->eat_number++;
	pthread_mutex_unlock(&(philosopher)->data->full);
	return (NULL);
}
