/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:28:48 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:28:26 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	set_mutex(int *ag, int content, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*ag = content;
	pthread_mutex_unlock(mutex);
}

void	set_arg(int *ag, int *content, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*ag = *content;
	pthread_mutex_unlock(mutex);
}

void	set_time_death(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->data->eat);
	philo->data->t_of_death = get_time() - philo->data->start_time
		- philo[philo->data->count].time_last_eat;
	pthread_mutex_unlock(&(philo)->data->eat);
}
