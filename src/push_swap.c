/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:41:32 by kri-              #+#    #+#             */
/*   Updated: 2026/06/04 18:50:17 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a, t_output *out)
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

static void	sort_small(t_stack **a, t_stack **b, t_output *out, int size)
{
	t_stack	*min;

	if (size == 3)
		sort_three(a, out);
	else if (size == 4)
	{
		min = find_min_node(*a);
		rotate_target_to_top(a, min, out);
		pb(a, b, out);
		sort_three(a, out);
		pa(a, b, out);
	}
	else if (size == 5)
	{
		min = find_min_node(*a);
		rotate_target_to_top(a, min, out);
		pb(a, b, out);
		min = find_min_node(*a);
		rotate_target_to_top(a, min, out);
		pb(a, b, out);
		sort_three(a, out);
		pa(a, b, out);
		pa(a, b, out);
	}
}

void	sort_stack(t_stack **a, t_stack **b, t_output *out)
{
	int	size;

	if (out->strategy == SIMPLE)
		insertion_based_sort(a, b, out);
	//else if (out->strategy == MEDIUM)
	//	medium_sort(a, b, out);
	else if (out->strategy == COMPLEX)
		radix_based_sort(a, b, out);
	else
	{
		size = stack_size(*a);
		if (size == 2)
		{
			if ((*a)->value > (*a)->next->value)
				sa(a, out);
		}
		else if (size <= 5)
			sort_small(a, b, out, size);
		else if (out->disorder < LOW_DISORDER)
			insertion_based_sort(a, b, out);
		else if (out->disorder > HIGH_DISORDER)
			radix_based_sort(a, b, out);
		//else
			//medium_sort(a, b, out);
	}
}

double	compute_disorder(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;
	double	disorder;

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
		return (0);
	disorder = (double)mistakes / (double)total_pairs ;
	return (disorder);
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

