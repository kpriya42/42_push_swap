/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:19:16 by kri-              #+#    #+#             */
/*   Updated: 2026/06/08 20:11:34 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_bits(int max_index)
{
	int		bits_count;

	bits_count = 0;
	while (max_index >> bits_count)
		bits_count++;
	return (bits_count);
}

void	radix_based_sort(t_stack **a, t_stack **b, t_output *out)
{
	int	i;
	int	bit;
	int	size;
	int	max_bits;

	i = 0;
	bit = 0;
	size = stack_size(*a);
	max_bits = find_max_bits(size - 1);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 1)
				ra(a, out);
			else
				pb(a, b, out);
			i++;
		}
		while (*b)
			pa(a, b, out);
		bit++;
	}
}
