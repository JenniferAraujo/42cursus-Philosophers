/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:48:57 by jennifera         #+#    #+#             */
/*   Updated: 2023/07/25 17:21:31 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%d %d %s\n", (get_time() - philo->data->start_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}
