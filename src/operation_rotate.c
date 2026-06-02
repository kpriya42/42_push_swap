/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:13:45 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:09:56 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	last = find_last(*head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_output *out)
{
	rotate(a);
	out->ra_count++;
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_stack **b, t_output *out)
{
	rotate(b);
	out->rb_count++;
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_stack **a, t_stack **b, t_output *out)
{
	rotate(a);
	rotate(b);
	out->rr_count++;
	ft_putendl_fd("rr", STDOUT_FILENO);
}
