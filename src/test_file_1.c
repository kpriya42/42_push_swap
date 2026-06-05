/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:58:24 by kri-              #+#    #+#             */
/*   Updated: 2026/06/05 18:06:56 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(const t_stack *a, const t_stack *b);
void	test_input(t_input clean_data);

void	test_input(t_input clean_data)
{
	puts("-----------------------------");
	printf("bench mark : %d\n", clean_data.bench_mark);
	printf("strategy type : %d\n", clean_data.strategy);
	printf("size of input : %d\n", clean_data.size);
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
