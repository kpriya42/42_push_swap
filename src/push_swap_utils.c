/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:08:19 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:18:45 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	t_stack	*templist;

	templist = stack;
	while (templist)
	{
		if (!templist->next)
			return (templist);
		templist = templist->next;
	}
	return (templist);
}

double	compute_disorder(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = head;
	while (current)
	{
		next = current->next;
		while (next)
		{
			total_pairs += 1;
			if (current->value > next->value)
				mistakes += 1;
			next = next->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.00);
	return ((double)mistakes / (double)total_pairs);
}

void	compute_total_ops(t_output *out)
{
	out->total_count += out->sa_count;
	out->total_count += out->sb_count;
	out->total_count += out->ss_count;
	out->total_count += out->ra_count;
	out->total_count += out->rb_count;
	out->total_count += out->rr_count;
	out->total_count += out->rra_count;
	out->total_count += out->rrb_count;
	out->total_count += out->rrr_count;
	out->total_count += out->pa_count;
	out->total_count += out->pb_count;
}
