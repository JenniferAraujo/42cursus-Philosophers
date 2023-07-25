/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/25 15:47:21 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_eat(t_philo *philo)
{
	philo->time_of_death = get_time() - philo->data->start_time + philo->time_of_death;
	ft_message(philo, EATING);
	if (philo->data->number_meals != -1)
		philo->eat_number++;
	return (NULL);
}