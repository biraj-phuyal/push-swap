/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:31:27 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 15:58:24 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rotate(t_stack *stack)
{
	if(!stack->head || !stack->head->next)
	stack->tail->val = stack->head->val;
	stack->head->val = stack->head->next->val;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
}

void ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}