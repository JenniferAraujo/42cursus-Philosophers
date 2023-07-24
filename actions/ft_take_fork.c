/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:00:03 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 20:46:50 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    ft_take_fork(t_philo   *philo)
{
    pthread_mutex_lock(philo->right_fork);
    ft_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_message(philo, "has taken a fork");
}