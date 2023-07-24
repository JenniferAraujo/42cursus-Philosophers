/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:23:51 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 20:26:06 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->list->write);
	printf("%lld philo number %d is thinking \n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->list->write);
}