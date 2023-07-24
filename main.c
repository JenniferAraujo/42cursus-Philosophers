/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:43:15 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 21:15:01 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	philo_create(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->list->number_philo)
	{
		if (i % 2 == 0)
		{
			pthread_create(&philos[i].philo, NULL, &routiene, &philos[i]);
			usleep(130);
		}
	}
	i = -1;
	while (++i < philos->list->number_philo)
	{
		if (i % 2 != 0)
		{
			pthread_create(&philos[i].philo, NULL, &routiene, &philos[i]);
			usleep(130);
		}
	}
}

int    init_args(t_list *list, int ac, char **av)
{
    list->number_philo = ft_atoi(av[1]);
    list->time_of_death = ft_atoi(av[2]);
    list->time_eat = ft_atoi(av[3]);
    list->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        list->number_meals = ft_atoi(av[5]);
    else
        list->number_meals = -1;
    if (list->number_philo <= 0 || list->number_philo > 200 || list->time_of_death < 0
		|| list->time_eat < 0 || list->time_sleep < 0)
		return (0); //ft_erorr
}

int	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
	else
		
}

int main(int ac, char **av)
{
    //t_list  *list;
    
    if (ac < 5 || ac > 6)
        return (0);
    if (!validations_args(av))
		return (0); //ft_erorr
}