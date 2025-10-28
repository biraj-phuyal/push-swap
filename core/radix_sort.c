/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:13:46 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/28 20:08:03 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_max_bits(t_stack *stack)
{
    int max;
    int bits;
    int i;
    t_node *cur;

	max = 0;
	bits = 0;
	i = 0;
	cur = stack->head;
    while (i < stack->size) {
        if (cur->idx > max) max = cur->idx;
        cur = cur->next;
        i++;
    }
    while ((max >> bits) != 0) 
		bits++;
    return (bits);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	int size;
    int bits;

	i = 0;
	bits = get_max_bits(stack_a);
    while (i < bits) 
	{
		j = 0;
        size = stack_a->size;
        while (j < size) 
		{
            int idx = stack_a->head->idx;
            if (((idx >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_b, stack_a);
            j++;
        }
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
        i++;
    }
}
