/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennifera <jennifera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:30:56 by jennifera         #+#    #+#             */
/*   Updated: 2023/07/19 11:32:28 by jennifera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_positive(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '-')
			j++;
	if (j % 2 == 0)
		return (1);
	return (0);
}