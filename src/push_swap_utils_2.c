/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:08:19 by kri-              #+#    #+#             */
/*   Updated: 2026/06/08 19:41:17 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

void	rotate_to_top(t_stack **stack, t_stack *target, t_output *out, int name)
{
	int	pos;

	if (!stack || !*stack || !target)
		return ;
	pos = get_node_pos(*stack, target);
	if (pos <= (stack_size(*stack)) / 2)
	{
		while (*stack != target)
		{
			if (name == STACKB)
				rb(stack, out);
			else
				ra(stack, out);
		}
	}
	else
	{
		while (*stack != target)
		{
			if (name == STACKB)
				rrb(stack, out);
			else
				rra(stack, out);
		}
	}
}
