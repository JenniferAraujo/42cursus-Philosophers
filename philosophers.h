/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/31 19:17:22 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"
# define RED     "\033[31m"
# define RESET     "\033[0m"

# define THINKING GREEN "is thinking"RESET
# define SLEEPING YELLOW "is sleeping"RESET
# define TAKE_FORK BLUE "has taken a fork"RESET
# define EATING CYAN "is eating"RESET
# define DIED RED "died"RESET
# define MESSAGE "ERROR"

typedef struct s_data 
{
	int					number_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_dif;
	int					number_meals;
	int					start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead;
	pthread_mutex_t		write;
	pthread_mutex_t		eat;
	int					i;
}						t_data;

typedef struct s_philo 
{
	int					id;
	t_data				*data;
	pthread_t			id_pthread;
	int					time_of_death;
	int					time_last_eat;
	int					left_fork;
	int					right_fork;
	int					eat_number;
}						t_philo;

/*                          INIT                  */
int     validations_args(char **av);
void	init_philo(t_philo *philo, t_data *data);
void	data_init(t_data *data);
void	philo_create(t_philo *philo, t_data *data);
void	*philo_routine(void *philo);
int     main(int ac, char **av);

/*                         UTILS                    */
long long	ft_atoi(const char *str); // ok
int         is_digit(char *str); // ok
int         is_positive(char *str); // ok

/*                          ACTIONS                 */
void	ft_message(t_philo *philo, char *str); // ok
void	*ft_eat(void *philo); // ok
int    *ft_take_fork_right(t_philo   *philo); // ok
int    *ft_take_fork_left(t_philo   *philo); // ok
int		*ft_drop_forks(t_philo *philo); // ok
void	*ft_thinking(t_philo *philo); // ok
void	ft_sleep(t_philo *philo); // ok
int     get_time(void); // ok
int		ft_usleep(int time);

/*							CHECK						*/
void	*check_die(void *philo);
//void    ft_free(t_data  *data);
//int		ft_error();

#endif