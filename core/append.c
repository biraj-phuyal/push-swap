/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:00:13 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/29 17:43:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*new_node(int val)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (node)
		node->val = val;
	return (node);
}

static void	push_back_first(t_stack *stack, t_node *node)
{
	node->next = node;
	node->prev = node;
	stack->head = node;
	stack->tail = node;
	stack->size = 1;
}

static void	push_back_nonempty(t_stack *stack, t_node *node)
{
	node->prev = stack->tail;
	node->next = stack->head;
	stack->tail->next = node;
	stack->head->prev = node;
	stack->tail = node;
	stack->size++;
}

bool	push_back(t_stack *stack, int val)
{
	t_node	*node;

	if (!stack)
		return (false);
	node = new_node(val);
	if (!node)
		return (false);
	if (stack->size == 0)
		push_back_first(stack, node);
	else
		push_back_nonempty(stack, node);
	return (true);
}
