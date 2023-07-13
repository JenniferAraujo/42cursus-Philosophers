/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/13 21:07:50 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
    struct s_data   *data;
    int id;
    int status;
    int time_die;
    int time_eat;
    int time_sleep;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;   
}   t_philo;

typedef struct s_data
{
    int number_philo;
    pthread_mutex_t philo;
}   t_data;


/*                          INIT                  */
void    *routine();
int main(int ac, char **av);

/*                          UTILS                         */
long long	ft_atoi(const char *str);

#endif