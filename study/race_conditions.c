/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:35 by jede-ara          #+#    #+#             */
/*   Updated: 2023/07/13 20:43:27 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

pthread_mutex_t mutex;

void* routine(void* mails) 
{
    int i = 0;
    int* ptr = (int*)mails;
    while (i++ < 10000000)
    {
        pthread_mutex_lock(&mutex);
        (*ptr)++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void)
{
    pthread_t   p1;
    pthread_t   p2;
    pthread_t   p3;
    pthread_t   p4;
    pthread_mutex_init(&mutex, NULL);
    int mails = 0;

    if(pthread_create(&p1, NULL, &routine, &mails) != 0)
        return (1);
    if (pthread_create(&p2, NULL, &routine, &mails) != 0)
        return (2);
    if(pthread_create(&p3, NULL, &routine, &mails) != 0)
        return (3);
    if (pthread_create(&p4, NULL, &routine, &mails) != 0)
        return (4);
    if (pthread_join(p1, NULL) != 0)
        return (5);
    if (pthread_join(p2, NULL) != 0)
        return (6);
     if (pthread_join(p3, NULL) != 0)
        return (7);
    if (pthread_join(p4, NULL) != 0)
        return (8);
    pthread_mutex_destroy(&mutex);
    printf("Numer of mails: %d", mails);
    return (0);
}
