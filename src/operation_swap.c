/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:17 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 19:03:17 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head || ((*head)->next == NULL))
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
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
