/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:08:23 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 17:38:01 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(const t_stack *a, const t_stack *b)
{
	t_stack	*atemp;
	t_stack	*btemp;

	atemp = (t_stack *) a;
	btemp = (t_stack *) b;
	printf("  A    B\n");
	while (atemp && btemp)
	{
		printf("  %d    %d\n", atemp->value, btemp->value);
		atemp = atemp->next;
		btemp = btemp->next;
	}
}
