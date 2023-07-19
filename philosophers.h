/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennifera <jennifera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/19 11:45:27 by jennifera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

# define EAT 0

typedef struct s_philo
{
    struct s_list   *list;
    int id; // id of the philo
    int status; // status of 
    int time_to_die; // id of the thread monitoring death
    int last_meal; // time of the last meal
    int number_eat; // number of meals;
    pthread_t   t1; // thread id
    pthread_mutex_t *right_fork; // right fork mutex
    pthread_mutex_t *left_fork; // left fork mutex
}   t_philo;

typedef struct s_list
{
    t_philo *philo;
    int number_philo; //number of philos
    int time_of_death; // time to die
    int time_eat; // time to eat
    int time_sleep; // time to sleep
    int number_meals; // must eat times
    int start_time; // start time in milliseconds
}   t_list;


/*                          INIT                  */
int     validations_args(char **av);
void    *routine();
int     main(int ac, char **av);

/*                         UTILS                    */
long long	ft_atoi(const char *str);
int         is_digit(char *str);
int         is_positive(char *str);

/*                          ACTIONS                 */
void    eat(t_philo *philo);
void    take_fork(t_philo   *philo);
void    drop_fork(t_philo   *philo);
int     get_time(void);
int     ft_usleep(int time);


#endif