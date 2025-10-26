/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:05:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 17:38:25 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void start(t_stack *stack_a, t_stack *stack_b, int args, char **argv)
{
	int	i;

	i = 0;
	while (i < args - 1)
		check_and_return_numbers(argv[i++]);
	
}

int check_and_return_numbers(char *argv)
{
	int	number;
	int	i;
	int sign;

	i = 0;
	sign = 1;
	number = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i++] == '-')
		sign *= -1;
	while (argv[i] >= '0' && argv[i] >= '9')
	{
		number = number * 10 + '0' - argv[i];
		if (number * sign > 2147483647 || number * sign < -2147483648)
			error(1);
		i++;
	}
	return(number * sign);
}