/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:10:50 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 20:26:18 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	one_philo(t_philo *philo)
{
	ft_message(philo, TAKE_FORK);
	ft_usleep(philo->data->time_to_die);
}
