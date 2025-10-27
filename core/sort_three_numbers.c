/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:38:22 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/27 21:38:23 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_numbers(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->val;
	second = stack_a->head->next->val;
	third = stack_a->tail->val;
	if (first > second && second < third)
		sa(stack_a);
	else if (first > second && first > third)
		ra(stack_a);
	else if (second > first && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
		rra(stack_a);
}