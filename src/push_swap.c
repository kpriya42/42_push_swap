/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:41:32 by kri-              #+#    #+#             */
/*   Updated: 2026/06/03 12:29:26 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, t_output *out)
{
	//if (out->strategy == SIMPLE)
		insertion_based_sort(a, b, out);
	//else if (out->strategy == MEDIUM)
	//	medium_sort(a, b, out);
	//else if (out->strategy == COMPLEX)
	//	complex_sort(a, b, out);
	//else if (out->strategy == ADAPTIVE)
	//{
	//	if (out->disorder < LOW_DISORDER)
	//		insertion_based_sort(a, b, out);
	//	else if (out->disorder >= LOW_DISORDER
	//		&& out->disorder <= HIGH_DISORDER)
	//		medium_sort(a, b, out);
	//	else
	//		complex_sort(a, b, out);
	//}
}

void	sort_three(t_stack **a, t_output *out)
{
	t_stack	*max;

	if (is_sorted(*a))
		return ;
	max = find_max_index_node(*a);
	if (max == *a)
		ra(a, out);
	else if (max == (*a)->next)
		rra(a, out);
	if ((*a)->next && (*a)->index > (*a)->next->index)
		sa(a, out);
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
