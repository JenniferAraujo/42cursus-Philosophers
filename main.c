/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennifera <jennifera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:43:15 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/24 13:10:26 by jennifera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*void    *routine()
{
    pthread_t    
}
void    init_philo()
{
    int i;
    t_list *philos;

    philos = malloc(sizeof(t_list) number_philo); //rever isso aqui
    
    
}*/

int    init_args(t_list *list, int ac, char **av)
{
    list->number_philo = ft_atoi(av[1]);
    list->time_of_death = ft_atoi(av[2]);
    list->time_eat = ft_atoi(av[3]);
    list->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        list->number_meals = ft_atoi(av[5]);
    else
        list->number_meals = -1;
    if (list->number_philo <= 0 || list->number_philo > 200 || list->time_of_death < 0
		|| list->time_eat < 0 || list->time_sleep < 0)
		return (0); //ft_erorr
}

int main(int ac, char **av)
{
    //t_list  *list;
    
    if (ac < 5 || ac > 6)
        return (0);
    if (!validations_args(av))
		return (0); //ft_erorr
}