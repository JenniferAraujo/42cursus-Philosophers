/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/26 18:03:16 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_eat(t_philo *philo)
{
	//printf("1 time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
	philo->time_of_death = get_time() - philo->time_last_eat - philo->data->start_time;
	philo->time_last_eat = get_time() - philo->data->start_time;
	//printf("2 time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
	if (philo->data->time_to_die < philo->time_of_death)
	{
		//printf("time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
		ft_message(philo, DIED);
		exit(0);
	}
	ft_message(philo, EATING);
	if (philo->data->number_meals != -1)
		philo->eat_number++;
	ft_usleep(philo->data->time_to_eat);
	return (NULL);
	
}