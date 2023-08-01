/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:28:48 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/01 21:53:32 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    set_mutex(int *ag, int content, pthread_mutex_t *mutex)
{
    pthread_mutex_lock(mutex);
    *ag = content;
    pthread_mutex_unlock(mutex);
}