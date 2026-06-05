/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:08:19 by kri-              #+#    #+#             */
/*   Updated: 2026/06/05 18:00:52 by kri-             ###   ########.fr       */
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

void	rotate_target_to_top(t_stack **stack, t_stack *target, t_output *out)
{
	int	size;
	int	pos;

	if (!stack || !*stack || !target)
		return ;
	size = stack_size(*stack);
	pos = get_node_pos(*stack, target);
	if (pos <= size / 2)
	{
		while (*stack != target)
			rb(stack, out);
	}
	else
	{
		while (*stack != target)
			rrb(stack, out);
	}
}
