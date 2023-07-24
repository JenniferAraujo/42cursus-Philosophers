/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:48:57 by jennifera         #+#    #+#             */
/*   Updated: 2023/07/24 17:18:49 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_message(char *str, t_philo *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->list->write);
	time = get_time() - philo->list->start_time;
	if (ft_strcmp(DIED, str) == 0 && philo->list->dead == 0)//quando morre
	{
		printf("%llu %d %s\n", time, philo->id, str);
		philo->list->dead = 1;
	}
	if (!philo->list->dead)//quando nao esta morto
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->list->write);
}