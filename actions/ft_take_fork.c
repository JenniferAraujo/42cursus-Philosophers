/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:00:03 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/26 15:54:33 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int    *ft_take_fork_right(t_philo   *philo)
{
    t_philo	*philosopher;

	philosopher = (t_philo *)philo;
    if (philo->id == philo->data->number_philo)
    {
        pthread_mutex_lock(&(philosopher->data->forks[0]));
        ft_message(philo, TAKE_FORK);
    }
    else
    {
        pthread_mutex_lock(&(philosopher->data->forks[philosopher->right_fork]));
        ft_message(philo, TAKE_FORK);
    }
	pthread_mutex_lock(&(philosopher->data->forks[philosopher->left_fork]));
	ft_message(philo, TAKE_FORK);
    return (0);
}

int    *ft_take_fork_left(t_philo   *philo)
{
    t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	pthread_mutex_lock(&(philosopher->data->forks[philosopher->left_fork]));
	ft_message(philo, TAKE_FORK);
	if (philo->id == philo->data->number_philo)
    {
        pthread_mutex_lock(&(philosopher->data->forks[0]));
        ft_message(philo, TAKE_FORK);
    }
    else
    {
        pthread_mutex_lock(&(philosopher->data->forks[philosopher->right_fork]));
        ft_message(philo, TAKE_FORK);
    }
    return (0);
}