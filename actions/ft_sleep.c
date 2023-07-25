/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:17:51 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/25 18:25:41 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(t_philo *philo)
{
	ft_message(philo, SLEEPING);
	ft_usleep(philo->data->time_to_sleep * 1000);
}