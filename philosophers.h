/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 20:47:53 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define TAKE_FORKS "has taken a fork"
# define EATING "is eating"
# define DIED "died"

typedef struct s_philo
{
    struct s_list   *list;
    int id; // id of the philo
    int status; // status of 
    int time_to_die; // id of the thread monitoring death
    int last_meal; // time of the last meal
    int number_eat; // number of meals;
    int	eat;
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
    int death;
    pthread_mutex_t write;
    pthread_mutex_t	lock;
}   t_list;

/*                          INIT                  */
int     validations_args(char **av);
/*void    *routine();*/
int     main(int ac, char **av);

/*                         UTILS                    */
long long	ft_atoi(const char *str); // ok
int         is_digit(char *str); // ok
int         is_positive(char *str); // ok
int         ft_strcmp(char *s1, char *s2); // ok

/*                          ACTIONS                 */
void    ft_eat(t_philo *philo); // fazer
void    ft_take_fork(t_philo   *philo); // ok
void    ft_drop_fork(t_philo   *philo); // ok
int     get_time(void); // ok
int     ft_usleep(int time); // ok
void	ft_message(char *str, t_philo *philo); //rever

#endif