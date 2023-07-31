/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:02:35 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 19:06:56 by jede-ara         ###   ########.fr       */
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
      pthread_mutex_destroy(data->write[i]);
      pthread_mutex_destroy(data->dead[i]);
      free(data);
      free(philo);
    }
}
int ft_error(char *str, t_list  *list)
{
    t_philo *philo;
    
    ft_message(philo, MESSAGE);
}