/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:53:34 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/27 18:10:41 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_eat(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	//printf("1 time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
	//philosopher ->time_of_death = get_time() - philosopher ->time_last_eat - philosopher ->data->start_time;
	//philosopher ->time_last_eat = get_time() - philosopher ->data->start_time;
	//printf("2 time to die: %d\n time of death:%d\n", philosopher ->data->time_to_die, philosopher ->time_of_death);
	/*if (philosopher ->data->time_to_die < philosopher ->time_of_death)
	{
		//printf("time to die: %d\n time of death:%d\n", philo->data->time_to_die, philo->time_of_death);
		ft_message(philo, DIED);
		exit(0);
	}*/
	ft_message(philo, EATING);
	if (philosopher->data->number_meals != -1)
		philosopher->eat_number++;
	ft_usleep(philosopher->data->time_to_eat);
	return (NULL);
	
}