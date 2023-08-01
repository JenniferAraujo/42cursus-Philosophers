/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:28:12 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/01 21:52:19 by jede-ara         ###   ########.fr       */
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
		philo[i].time_last_eat = 0;
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
	data->i = 0;
	data->meals = 0;
	data->death = 0;
	//pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->eat, NULL);
	//pthread_mutex_lock(&data->dead);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->number_philo);
	while (i < data->number_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
}

void	philo_create(t_philo *philo, t_data *data, pthread_t *pthread_id)
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
	}
	pthread_create(pthread_id, NULL, (void *)check_die, philo);
}
void	philo_join(t_philo *philo, t_data *data, pthread_t *pthread_id)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_join(philo[i].id_pthread, NULL))
		{
			printf("Error\n");
			return ;
		}
		i++;
	}
	pthread_join(*pthread_id, NULL);
}
