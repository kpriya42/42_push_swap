/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:08:19 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 12:21:31 by kri-             ###   ########.fr       */
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
