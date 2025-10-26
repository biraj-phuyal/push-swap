/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:19:01 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 15:03:07 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void swap(t_stack *stack)
{
	if(!stack->head || !stack->head->next)
	stack->tail = stack->head;
	stack->head = stack->head;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
}

void sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 1);
}

void sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 1);
}

void sb(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 1);
}