/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:43:15 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 21:14:37 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_args(t_data *data, char **av, int ac)
{
	data->number_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->time_dif = data->time_to_eat - data->time_to_sleep + 10;
	if (ac == 6)
		data->number_meals = ft_atoi(av[5]);
	else
		data->number_meals = -1;
	if (data->number_philo <= 0 || data->number_philo > 200
		|| data->time_to_die < 0 || data->time_to_eat < 0 
		|| data->time_to_sleep < 0)
		return (0);
	return (0);
}

int	ft_init(t_data *data, char **av, int ac)
{
	if (init_args(data, av, ac))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philo;
	pthread_t	pthread_id;

	if (ac < 5 || ac > 6)
	{
		printf("Error\n");
		return (1);
	}
	if (!validations_args(av))
	{
		printf("Error\n");
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	ft_init(data, av, ac);
	philo = malloc(sizeof(t_philo) * data->number_philo);
	init_philo(philo, data);
	data_init(data);
	data->start_time = get_time();
	philo_create(philo, data, &pthread_id);
	philo_join(philo, data, &pthread_id);
	ft_free(philo, data);
	return (0);
}
