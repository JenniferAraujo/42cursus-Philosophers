/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennifera <jennifera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:26:17 by jennifera         #+#    #+#             */
/*   Updated: 2023/07/19 11:31:50 by jennifera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validations_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!is_digit(av[i]))
			return (0);
		if (!is_positive(av[i]))
			return (0);
		if (ft_atoi(av[i]) <= 0)
			return (0);
	}
	return (1);
}