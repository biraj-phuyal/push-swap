/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:05:54 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/26 16:05:32 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int args, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	start(stack_a, stack_b, args, argv);
	if (!ordered(stack_a))
	{
		if (stack_a->size == 2)
			sa(stack_a);
	}
		
	return (0);
}