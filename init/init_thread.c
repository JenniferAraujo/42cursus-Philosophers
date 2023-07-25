/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:28:12 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/25 18:01:02 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].time_of_death = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->number_philo;
		philo[i].eat_number = 0;
		i++;
	}
}

void	data_init(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->life, NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_lock(&data->life);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->number_philo);
	while (i < data->number_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
}

void	philo_create(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&philo[i].id_pthread, NULL, philo_routine, (void *)&philo[i]))
		{
			printf("Error\n");
			return ;
		}
		i++;
		usleep(100);
	}
}
