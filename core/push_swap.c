/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:05:54 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/27 23:11:14 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	process_indexing(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;
	int		idx;
	int		i;
	int		j;

	if (!stack)
		return ;
	idx = 0;
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		checker = stack->head;
		while (j < stack->size)
		{
			if (current->val > checker->val)
				idx++;
			checker = checker->next;
			j++;
		}
		current->idx = idx;
		idx = 0;
		current = current->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a = ft_calloc(sizeof(t_stack), 1);
	t_stack *stack_b = ft_calloc(sizeof(t_stack), 1);

	if (!stack_a || !stack_b)
		return (1);
	if (!start(stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ordered(stack_a))
	{
		if (stack_a->size == 2)
			sa(stack_a);
		else if (stack_a->size == 3)
			sort_three_numbers(stack_a);
		else if (stack_a->size == 4)
			sort_four_numbers(stack_a, stack_b);
	}
}