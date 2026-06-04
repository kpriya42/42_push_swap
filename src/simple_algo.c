/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:23:37 by kri-              #+#    #+#             */
/*   Updated: 2026/06/04 13:32:40 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_target_to_top(t_stack **b, t_stack *target, t_output *out)
{
	int	size;
	int	pos;

	if (!b || !*b || !target)
		return ;
	size = stack_size(*b);
	pos = get_node_pos(*b, target);
	if (pos <= size / 2)
	{
		while (*b != target)
			rb(b, out);
	}
	else
	{
		while (*b != target)
			rrb(b, out);
	}
}

static void	rotate_max_to_top(t_stack **b, t_output *out)
{
	t_stack	*max;

	if (!b || !*b)
		return ;
	max = find_max_node(*b);
	rotate_target_to_top(b, max, out);
}

static void	insert_avalue_in_b(t_stack **a, t_stack **b, int value,\
	t_output *out)
{
	t_stack	*target_pos;

	target_pos = *b;
	while (target_pos)
	{
		if (target_pos->value < value)
			break ;
		target_pos = target_pos->next;
	}
	rotate_target_to_top(b, target_pos, out);
	pb(a, b, out);
}

static void	insert_top_a_into_b(t_stack **a, t_stack **b, t_output *out)
{
	int		avalue;
	t_stack	*min;
	t_stack	*max;

	if (!b || !*b)
	{
		pb(a, b, out);
		return ;
	}
	avalue = (*a)->value;
	min = find_min_node(*b);
	max = find_max_node(*b);
	if (avalue > max->value)
	{
		pb(a, b, out);
		return ;
	}
	if (avalue < min->value)
	{
		pb(a, b, out);
		rb(b, out);
		return ;
	}
	insert_avalue_in_b(a, b, avalue, out);
	rotate_max_to_top(b, out);
}
	//target = find_insert_position_in_b(*b, value);
	//rotate_b_to_top(b, target, out);
	//pb(a, b, out);

void	insertion_based_sort(t_stack **a, t_stack **b, t_output *out)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	while (*a)
		insert_top_a_into_b(a, b, out);
	while (*b)
		pa(a, b, out);
}
