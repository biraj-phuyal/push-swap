/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:05:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/27 23:12:41 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack)
		return ;
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	stack->head = NULL;
	stack->tail = NULL;
}

long strict_atoi(char *argv)
{
    long sign;
    long number;
    int  i;

	i = 0;
	number = 0;
	sign = 1;
    while (ft_isspace(argv[i]))
        i++;
    if (argv[i] && (argv[i] == '+' || argv[i] == '-'))
    {
        sign *= -1;
        i++;
    }
    if (!ft_isdigit(argv[i]))
        return (LONG_MIN);
    while (ft_isdigit(argv[i]))
    {
        number = number * 10 + (argv[i] - '0');
        if (sign * number > 2147483647L || sign * number < -2147483648L)
            return (LONG_MIN);
        i++;
    }
    return ((int)(sign * number));
}

bool	start(t_stack *stack, int argc, char **argv)
{
    int  i;
    long  number;

	i = 1;
    while (i < argc)
    {
        number = strict_atoi(argv[i]);
        if (number == LONG_MIN)
			return (free_stack(stack), false);
        push_back(stack, number);
        i++;
    }
	if (has_duplicate(stack))
		return (free_stack(stack), false);
	process_indexing(stack);
    return (true);
}
