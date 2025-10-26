/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:05:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 22:53:20 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void stack_init(t_stack *stack)
{
    stack->head = 0;
    stack->tail = 0;
    stack->size = 0;
    stack->is_circular = 1;
}

t_stack *start(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
    int  i;
    int  number;

    (void)stack_a;
	i = 0;
    stack_init(stack_a);
    while (i < argc)
    {
        number = check_and_return_numbers(argv[i]);
        if (!check_and_return_numbers) 
			error(1);
        if (has_duplicate(stack_a, number))
			error(0);
        push_back(stack_a, number);
        i++;
    }
    return (stack_a);
}

int check_and_return_numbers(char *argv)
{
    long sign;
    long number;
    int  i;

	i = 0;
	number = 0;
	sign = 1;
    while ((argv[i] == '0' || argv[i] == '\t') && argv[i])
        i++;
    if (argv[i] == '+' || argv[i] == '-')
    {
        sign *= -1;
        i++;
    }
    if (!(argv[i] >= '0' && argv[i] <= 0))
        return 0;
    while (!(argv[i] >= '0' && argv[i] <= 0) && argv[i])
    {
        number = number * 10 + (argv[i] - '0');
        if (sign * number > 2147483647L || sign * number < -2147483648L)
            error(1);
        i++;
    }
    return (int)(sign * number);
}