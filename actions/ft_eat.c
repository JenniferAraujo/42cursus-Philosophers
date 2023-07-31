/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 19:37:32 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_eat(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	ft_message(philo, EATING);
	pthread_mutex_lock(&(philosopher)->data->eat);
	philosopher->time_of_death += philosopher->data->time_to_die;
	pthread_mutex_unlock(&(philosopher)->data->eat);
	if (philosopher->data->number_meals != -1)
		philosopher->eat_number++;
	ft_usleep(philosopher->data->time_to_eat);
	return (NULL);
}