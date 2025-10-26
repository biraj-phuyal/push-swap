/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:24:12 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 15:39:37 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_node {
    int              val;
    int              idx;
    int              pos;
    int              target;
    int              cost_a;
    int              cost_b;
    struct s_node   *prev;
    struct s_node   *next;
} t_node;

typedef struct s_stack {
    t_node *head;
    t_node *tail;
    int     size;
    int     is_circular;
} t_stack;

void swap(t_stack *stack);
void rotate(t_stack *stack);


void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);


#endif
