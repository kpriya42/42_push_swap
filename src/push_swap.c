/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:41:32 by kri-              #+#    #+#             */
/*   Updated: 2026/06/02 14:15:39 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(const t_stack *a, const t_stack *b);

void	sort_stack(t_stack *a, t_stack *b, t_output *out)
{
	printf ("original\n");
	display_stack(a, b);
	sa(&a, out);
	sb(&b, out);
	display_stack(a, b);
	ra(&a, out);
	display_stack(a, b);
	rra(&a, out);
	rra(&a, out);
	display_stack(a, b);
	pa(&a, &b, out);
	pa(&a, &b, out);
	display_stack(a, b);
	pb(&a, &b, out);
	display_stack(a, b);
}
