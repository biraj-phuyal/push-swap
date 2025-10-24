/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:24:12 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/24 21:23:10 by biphuyal         ###   ########.fr       */
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

int	get_len(long n);

#endif
