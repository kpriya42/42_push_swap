/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:05:04 by kri-              #+#    #+#             */
/*   Updated: 2026/06/08 16:56:51 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_chunks(t_stack **a)
{
	int	chunk_size;
	int	size;

	chunk_size = 0;
	size = stack_size(*a);
	while (chunk_size * chunk_size < size)
		chunk_size ++;
	return (chunk_size);
}

void	move_chunks(t_stack **a, t_stack **b, t_output *out, int chunk_size)
{
	int	current_chunk;
	int	count;
	int	chunk_num;

	count = 0;
	current_chunk = 0;
	while (current_chunk < chunk_size)
	{
		count = chunk_size;
		while (*a && count > 0)
		{
			chunk_num = (*a)->index / chunk_size;
			if (chunk_num == current_chunk)
			{
				pb(a, b, out);
				count --;
			}
			else
				ra(a, out);
		}
		current_chunk ++;
	}
}

void	sort_push(t_stack **a, t_stack **b, t_output *out)
{
	t_stack	*max_node;

	while (*b)
	{
		max_node = find_max_node(*b);
		rotate_target_to_top(b, max_node, out);
		pa(a, b, out);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_output *out)
{
	int	size;

	size = divide_chunks(a);
	move_chunks(a, b, out, size);
	sort_push(a, b, out);
}
