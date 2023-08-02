/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:23:04 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:18:46 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*check_die(t_philo *philo)
{
	while (1)
	{
		philo->data->count = -1;
		while (++philo->data->count < philo->data->number_philo)
		{
			set_arg(&philo->data->temp, &philo->data->meals,
				&(philo)->data->end);
			if (philo->data->temp == 1)
				return (NULL);
			set_time_death(philo);
			if (philo->data->t_of_death > philo->data->time_to_die)
			{
				set_mutex(&philo->data->death, 1, &philo->data->end);
				pthread_mutex_lock(&philo->data->write);
				printf("%d %d \033[31mdied\n\033[0m", get_time()
					- philo->data->start_time, philo[philo->data->count].id);
				pthread_mutex_unlock(&philo->data->write);
				return (NULL);
			}
		}
	}
	return (NULL);
}
