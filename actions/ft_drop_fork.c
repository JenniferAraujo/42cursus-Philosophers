/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:59:27 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 18:23:09 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	*ft_drop_forks(t_philo *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->right_fork]));
	pthread_mutex_unlock(&(philosopher->data->forks[philosopher->left_fork]));
	return (0);
}