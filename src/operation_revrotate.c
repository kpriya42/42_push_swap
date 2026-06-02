/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_revrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:32:19 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:09:06 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = find_last(*head);
	last->next = *head;
	last->prev->next = NULL;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
}

void	rra(t_stack **a, t_output *out)
{
	reverse_rotate(a);
	out->rra_count++;
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack **b, t_output *out)
{
	reverse_rotate(b);
	out->rrb_count++;
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack **a, t_stack **b, t_output *out)
{
	reverse_rotate(a);
	reverse_rotate(b);
	out->rrr_count++;
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
