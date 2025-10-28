/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:24:12 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/28 17:54:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

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

int		error(int code);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
int		ordered(t_stack *stack);
bool	has_duplicate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		minimum_number(t_stack *stack_a);
void	process_indexing(t_stack *stack);
bool    push_back(t_stack *stack, int val);
void	sort_three_numbers(t_stack *stack_a);
void	rotate_to_top(t_stack *stack_a, int pos);
bool	start(t_stack *stack, int argc, char **argv);
void    sort_four_numbers(t_stack *stack_a, t_stack *stack_b);
void sort_five_numbers(t_stack *stack_a, t_stack *stack_b);


void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_b, t_stack *stack_a);
void ss(t_stack *stack_a, t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

#endif
