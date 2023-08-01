/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:02:49 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/01 19:08:49 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
					return (0);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}