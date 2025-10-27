/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:19:01 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/27 15:08:35 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void swap(t_stack *stack_a)
{
    int tmp;

    if (!stack_a || stack_a->size < 2)
        return ;
    tmp = stack_a->head->val;
    stack_a->head->val = stack_a->head->next->val;
    stack_a->head->next->val = tmp;
}

void sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}