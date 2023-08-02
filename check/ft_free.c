/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:02:35 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:50:59 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_free(t_philo *philo, t_data *data)
{
	int	i;
	int	philosopher;

	i = -1;
	philosopher = data->number_philo;
	while (++i < philosopher)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->full);
	pthread_mutex_destroy(&data->end);
	free(data->forks);
	free(philo);
	free(data);
}
