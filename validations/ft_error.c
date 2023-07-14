/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:02:35 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/14 20:27:06 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//destroy mutex 
void    ft_free(t_list  *list)
{
    pthread_mutex_destroy()
    free(list);
}

//chamar a ft_exit
int ft_error(char *str, t_list  *list)
{
    
}