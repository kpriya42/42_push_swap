/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:58:24 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 20:34:04 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(const t_stack *a, const t_stack *b);

void	test_input(t_input clean_data)
{
	//int		i;

	puts("-----------------------------");
	printf("bench mark : %d\n", clean_data.bench_mark);
	printf("strategy type : %d\n", clean_data.strategy);
	printf("size of input : %d\n", clean_data.size);
	//i = 0;
	//while (i < clean_data.size)
	//{
	//	printf("args unsorted order :%d\n", clean_data.numbers[i]);
	//	i ++;
	//}
}
