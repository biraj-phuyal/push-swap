/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:00:13 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 22:52:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node *new_node(int val)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(*node));
    if (!node)
        rror(2);
    node->val    = val;
    node->idx    = 0;
    node->pos    = 0;
    node->target = 0;
    node->cost_a = 0;
    node->cost_b = 0;
    node->next   = NULL;
    node->prev   = NULL;
    return (node);
}

static void push_back_first(t_stack *stack, t_node *node)
{
    node->next = node;
    node->prev = node;
    stack->head = node;
    stack->tail = node;
    stack->size = 1;
}

static void push_back_nonempty(t_stack *stack, t_node *node)
{
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->tail = node;
    stack->size++;
}

void    push_back(t_stack *stack, int val)
{
    t_node *node;

    if (!stack)
        error(3);
    node = new_node(val);
    if (stack->size == 0)
    {
        push_back_first(stack, node);
        return ;
    }
    push_back_nonempty(stack, node);
}
