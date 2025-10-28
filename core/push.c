/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:02:11 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/28 19:46:39 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node *take_the_head(t_stack *stack)
{
	t_node *head;

	if (!stack || stack->size == 0)
		return (NULL);
	head = stack->head;
	if (stack->size == 1)
	{
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		stack->head = head->next;
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
	}
	stack->size--;
	head->next = head;
	head->prev = head;
	return (head);
}

void push(t_stack *stack, t_node *head)
{
	if (!stack || !head)
		return ;
	if (stack->size == 0)
	{
		head->next = head;
		head->prev = head;
		stack->head = head;
		stack->tail = head;
	}
	else
	{
		head->next = stack->head;
		head->prev = stack->tail;
		stack->head->prev = head;
		stack->tail->next = head;
		stack->head = head;
	}
	stack->size++;
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node *head;

	if (!stack_b)
		return ;
	head = take_the_head(stack_b);
	if (head)
		push(stack_a, head);
	write(1, "pa\n", 3);
}

void pb(t_stack *stack_b, t_stack *stack_a)
{
	t_node *head;

	if (!stack_a)
		return ;
	head = take_the_head(stack_a);
	if (head)
		push(stack_b, head);
	write(1, "pb\n", 3);
}