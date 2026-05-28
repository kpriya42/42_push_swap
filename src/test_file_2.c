/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:58:24 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 20:35:34 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(const t_stack *a, const t_stack *b);

void	test_operations(t_stack *a, t_stack *b)
{
	printf ("original\n");
	display_stack(a, b);
	sa(&a);
	sb(&b);
	printf ("sa sb\n");
	display_stack(a, b);
	ra(&a);
	printf ("ra \n");
	display_stack(a, b);
	printf ("rra rra\n");
	rra(&a);
	rra(&a);
	display_stack(a, b);
	pa(&a,&b);
	pa(&a,&b);
	printf ("pa pa \n");
	display_stack(a, b);
	pb(&a,&b);
	printf ("pb \n");
	display_stack(a, b);
}

void	display_stack(const t_stack *a, const t_stack *b)
{
	t_stack	*atemp;
	t_stack	*btemp;
	int		aval;
	int		bval;

	atemp = (t_stack *) a;
	btemp = (t_stack *) b;
	printf("----------------\n    A    B\n----------------\n");
	while (atemp || btemp)
	{
		if (!atemp)
			aval = 0;
		else
			aval = atemp->value;
		if (!btemp)
			bval = 0;
		else
			bval = btemp->value;
		printf("    %d    %d\n", aval, bval);
		if (atemp)
			atemp = atemp->next;
		if (btemp)
			btemp = btemp->next;
	}
}
