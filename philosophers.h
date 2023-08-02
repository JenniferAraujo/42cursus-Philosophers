/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/02 22:27:40 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define THINKING "\033[32mis thinking\033[0m"
# define SLEEPING "\033[33mis sleeping\033[0m"
# define TAKE_FORK "\033[34mhas taken a fork\033[0m"
# define EATING "\033[36mis eating\033[0m"
# define DIED "\033[31mdied\033[0m"

typedef struct s_data 
{
	int					number_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_dif;
	int					number_meals;
	int					start_time;
	int					meals;
	int					death;
	int					i;
	int					count;
	int					t_of_death;
	int					temp;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write;
	pthread_mutex_t		eat;
	pthread_mutex_t		full;
	pthread_mutex_t		end;
	pthread_mutex_t		data;
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
int			validations_args(char **av);
void		init_philo(t_philo *philo, t_data *data);
void		data_init(t_data *data);
void		philo_create(t_philo *philo, t_data *data, pthread_t *pthread_id);
void		philo_join(t_philo *philo, t_data *data, pthread_t *pthread_id);
void		one_philo(t_philo *philo);
void		*philo_routine(void *philo);
int			main(int ac, char **av);

/*                         UTILS                    */
long long	ft_atoi(const char *str); // ok
int			is_digit(char *str); // ok
int			is_positive(char *str); // ok
void		set_mutex(int *ag, int content, pthread_mutex_t *mutex);
void		set_arg(int *ag, int *content, pthread_mutex_t *mutex);
void		set_time_death(t_philo *philo);

/*                          ACTIONS                 */
void		ft_message(t_philo *philo, char *str); // ok
void		*ft_eat(void *philo); // ok
int			*ft_take_fork_right(t_philo *philo); // ok
int			*ft_take_fork_left(t_philo *philo); // ok
int			*ft_drop_forks(t_philo *philo); // ok
void		*ft_thinking(t_philo *philo); // ok
void		ft_sleep(t_philo *philo); // ok
int			get_time(void); // ok
int			ft_usleep(int time);

/*							CHECK						*/
void		*check_die(t_philo *philo);
void		*check_full(void *philo);
void		ft_free(t_philo *philo, t_data *data);
void		ft_error(t_philo *philo, t_data *data);

#endif
