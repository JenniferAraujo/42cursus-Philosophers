/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:17:51 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 20:26:10 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	sleeping(int ms)
{
	int	ft_time;

	ft_time = get_time();
	while (get_time() - ft_time < ms)
		usleep(50);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->list->write);
	printf("%lld philo number %d is sleeping \n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->list->write);
	sleeping(philo->list->time_sleep);
}