/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:55:53 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:06:54 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_full(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	pthread_mutex_lock(&(philosopher)->data->full);
	if (philosopher->eat_number == philosopher->data->number_meals)
	{
		philosopher->eat_number = -1;
		philosopher->data->i++;
	}
	if (philosopher->data->i == philosopher->data->number_philo)
		set_mutex(&philosopher->data->meals, 1, &philosopher->data->end);
	pthread_mutex_unlock(&(philosopher)->data->full);
	return (NULL);
}
