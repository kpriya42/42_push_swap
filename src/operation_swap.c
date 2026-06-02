/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:35:17 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:10:25 by kri-             ###   ########.fr       */
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

void	sa(t_stack **a, t_output *out)
{
	swap_top(a);
	out->sa_count++;
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack **b, t_output *out)
{
	swap_top(b);
	out->sb_count++;
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack **a, t_stack **b, t_output *out)
{
	swap_top(a);
	swap_top(b);
	out->ss_count++;
	ft_putendl_fd("ss", STDOUT_FILENO);
}
