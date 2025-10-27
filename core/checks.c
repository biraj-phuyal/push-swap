/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:19:13 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/27 22:11:58 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ordered(t_stack *stack)
{
    t_node *current;
    int i;

    if (!stack || stack->size <= 1)
        return (1);
    current = stack->head;
    i = 0;
    while (i < stack->size - 1)
    {
        if (current->val > current->next->val)
            return (0);
        current = current->next;
        i++;
    }
    return (1);
}

bool has_duplicate(t_stack *stack)
{
	t_node *current;
	t_node *checker;
	int i;
	int j;

	if (!stack)
		return (false);
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		checker = current->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (current->val == checker->val)
				return (true);
			checker = checker->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (false);
}