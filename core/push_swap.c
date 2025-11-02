/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:05:54 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/02 17:22:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	process_indexing(t_stack *stack)
{
	t_node	*cur;
	t_node	*chk;
	int		idx;
	int		count;
	int		c;

	if (!stack)
		return ;
	cur = stack->head;
	count = stack->size;
	while (count--)
	{
		idx = 0;
		chk = stack->head;
		c = stack->size;
		while (c--)
		{
			if (cur->val > chk->val)
				idx++;
			chk = chk->next;
		}
		cur->idx = idx;
		cur = cur->next;
	}
}

void	call_sorts(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three_numbers(stack_a);
	else if (stack_a->size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five_numbers(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_b = ft_calloc(sizeof(t_stack), 1);
	if (!start(stack_a, argc, argv))
	{
		free(stack_a);
		free(stack_b);
		exit(write(2, "Error\n", 6));
	}
	if (!ordered(stack_a))
		call_sorts(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}