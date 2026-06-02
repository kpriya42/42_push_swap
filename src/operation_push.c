/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:22:23 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:07:19 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*head2;

	if (!stack2 || !(*stack2))
		return ;
	head2 = *stack2;
	*stack2 = head2->next;
	if (*stack2)
		(*stack2)->prev = NULL;
	head2->next = *stack1;
	head2->prev = NULL;
	if (*stack1)
		(*stack1)->prev = head2;
	*stack1 = head2;
}

void	pa(t_stack **a, t_stack **b, t_output *out)
{
	push(a, b);
	out->pa_count++;
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_stack **a, t_stack **b, t_output *out)
{
	push(b, a);
	out->pb_count++;
	ft_putendl_fd("pb", STDOUT_FILENO);
}
