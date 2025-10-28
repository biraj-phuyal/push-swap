/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:48:12 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/28 18:11:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int pos;

	pos = minimum_number(stack_a);
    rotate_to_top(stack_a, pos);
    pb(stack_b, stack_a);
}

void sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	if (stack_b->head->val < stack_b->head->next->val)
		sb(stack_b);
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}