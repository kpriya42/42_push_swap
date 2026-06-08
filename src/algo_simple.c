/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:23:37 by kri-              #+#    #+#             */
/*   Updated: 2026/06/08 19:42:57 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_max_to_top(t_stack **b, t_output *out)
{
	t_stack	*max;

	if (!b || !*b)
		return ;
	max = find_max_node(*b);
	rotate_to_top(b, max, out, STACKB);
}

static void	insert_avalue_in_b(t_stack **a, t_stack **b, t_output *out)
{
	int		avalue;
	t_stack	*pos_to_insert;

	pos_to_insert = *b;
	avalue = (*a)->value;
	while (pos_to_insert)
	{
		if (pos_to_insert->value < avalue)
			break ;
		pos_to_insert = pos_to_insert->next;
	}
	rotate_to_top(b, pos_to_insert, out, STACKB);
	pb(a, b, out);
	rotate_max_to_top(b, out);
}

void	insertion_based_sort(t_stack **a, t_stack **b, t_output *out)
{
	int		avalue;
	t_stack	*min;
	t_stack	*max;

	if (!a || !*a || is_sorted(*a))
		return ;
	printf("In simple\n");
	while (*a)
	{
		if (!b || !*b)
			pb(a, b, out);
		avalue = (*a)->value;
		min = find_min_node(*b);
		max = find_max_node(*b);
		if (avalue > max->value)
			pb(a, b, out);
		else if (avalue < min->value)
		{
			pb(a, b, out);
			rb(b, out);
		}
		else
			insert_avalue_in_b(a, b, out);
	}
	while (*b)
		pa(a, b, out);
}
