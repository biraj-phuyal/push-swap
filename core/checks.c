/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:19:13 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 23:00:11 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ordered(t_stack *stack)
{
    t_node *current;
    int i;

    if (!stack || stack->size <= 1)
        return (1);
    current = stack->head;
    i = 0;
    while (i < stack->size - 1)
    {
        if (current->val > current->next->val)
            return (0);
        current = current->next;
        i++;
    }
    return (1);
}

int has_duplicate(t_stack *stack, int number)
{
    t_node *current;
    int i;

    if (!stack || stack->size == 0)
        return 0;
    current = stack->head;
    i = 0;
    while (i < stack->size)
    {
        if (current->val == number)
            return (1);
        current = current->next;
        i++;
    }
    return (0);
}