/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:17 by kri-              #+#    #+#             */
/*   Updated: 2026/05/26 17:26:41 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_top(t_stack **node)
{
	t_stack	*top;
	t_stack	*second;

	top = *node;
	second = top->next;
	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;
	second->prev = NULL;
	second->next = top;
	top->prev = second;
	*node = second;
}

void	sa(t_stack **a)
{
	swap_top(a);
}

void	sb(t_stack **b)
{
	swap_top(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top(a);
	swap_top(b);
}
