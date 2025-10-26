/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:19:13 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 19:57:04 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int check_if_numbers_are_ordered(t_stack *a)
{
    t_node *cur;
    int     i;

    if (!a || a->size <= 1)
        return (1);
    cur = a->head;
    i = 0;
    while (i < a->size - 1)
    {
        if (cur->val > cur->next->val)
            return (0);
        cur = cur->next;
        i++;
    }
    return (1);
}

int duplicated(int nums, t_stack *a)
{
    t_node *cur;
    int     i;

    if (!a || a->size == 0)
        return (1);
    cur = a->head;
    i = 0;
    while (i < a->size)
    {
        if (cur->val == nums)
            return (0);
        cur = cur->next;
        i++;
    }
    return (1);
}
