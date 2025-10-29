/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:38:38 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/29 19:40:52 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	minimum_number(t_stack *stack_a)
{
	int		pos;
	int		best_pos;
	int		best_val;
	t_node	*current;

	best_val = stack_a->head->val;
	pos = 0;
	best_pos = 0;
	current = stack_a->head;
	while (pos < stack_a->size)
	{
		if (current->val < best_val)
		{
			best_val = current->val;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}

void	rotate_to_top(t_stack *stack_a, int pos)
{
	int	i;

	if (pos <= stack_a->size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		i = stack_a->size - pos;
		while (i-- > 0)
			rra(stack_a);
	}
}

void	sort_four_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	pos = minimum_number(stack_a);
	rotate_to_top(stack_a, pos);
	pb(stack_b, stack_a);
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
}
