/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:59:27 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/25 17:48:40 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	*ft_drop_forks(t_philo *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->right_fork]));
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->left_fork]));
	ft_message(philo, SLEEPING);
	//ft_usleep(philo->data->time_to_sleep);
	return (0);
}