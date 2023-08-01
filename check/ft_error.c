/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:02:35 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/01 21:52:34 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    ft_free(t_philo *philo, t_data  *data)
{
    int i;
    int number;

    i = -1;
    number = data->number_philo;
    while (++i < number)
    {
      pthread_mutex_destroy(&data->forks[i]);
      pthread_mutex_destroy(&data->write);
      //pthread_mutex_destroy(&data->dead);
      free(data);
      free(philo);
    }
}
int ft_error(t_philo  *philo, t_data *data)
{   
    ft_message(philo, ERROR);
    free(data);
    return (0);
}