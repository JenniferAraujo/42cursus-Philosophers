/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/14 15:02:26 by jede-ara         ###   ########.fr       */
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
    pthread_t   t1;
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
}   t_data;


/*                          INIT                  */
void    *routine();
int main(int ac, char **av);

/*                         UTILS                    */
long long	ft_atoi(const char *str);

/*                          ACTIONS                 */
void    eat(t_philo *philo);
void    take_fork(t_philo   *philo);
void    drop_fork(t_philo   *philo);

#endif