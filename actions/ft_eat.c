/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 21:14:33 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	   ft_eat(t_philo *philo)
{
   	ft_take_forks(philo);
	pthread_mutex_lock(philo->locks);
	philo->time_to_die = get_time() + philo->list->time_of_death;
	ft_message(philo, "is eating");
	philo->number_eat++;
	ft_usleep(philo->list->time_eat);
	pthread_mutex_unlock(&philo->locks);
	ft_drop_forks(philo);
}
