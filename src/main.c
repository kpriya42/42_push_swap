/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:53:08 by meqian            #+#    #+#             */
/*   Updated: 2026/06/09 19:22:38 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **splited_arry)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_split(splited_arry);
	exit (1);
}

t_input	parse_args(int ac, char **av)
{
	t_input	data;
	char	**splited_av;
	int		i;

	i = -1;
	splited_av = split_input(ac, av);
	if (!splited_av)
		error_exit(av);
	data.bench_mark = check_bench(splited_av);
	data.strategy = strategy_selector(splited_av);
	data.size = 0;
	while (splited_av[data.size])
		data.size++;
	data.numbers = malloc(sizeof(int) * data.size);
	while (++i < data.size)
		data.numbers[i] = check_convert(splited_av[i], splited_av,
				data.numbers);
	if (check_dup(data.numbers, data.size))
	{
		free(data.numbers);
		error_exit(splited_av);
	}
	free_split(splited_av);
	return (data);
}

int	main(int ac, char **av)
{
	t_input		clean_data;
	t_stack		*a;
	t_stack		*b;
	t_output	out;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	check_space(av);
	clean_data = parse_args(ac, av);
	a = init_stack(clean_data);
	free(clean_data.numbers);
	if (a)
	{
		init_out(&clean_data, a, &out);
		if (out.disorder > 0.0)
			sort_stack(&a, &b, &out);
		compute_total_ops(&out);
		if (clean_data.bench_mark)
			bench_output(out);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

//void	test_input(t_input clean_data)
//{
//	puts("-----------------------------");
//	printf("bench mark : %d\n", clean_data.bench_mark);
//	printf("strategy type : %d\n", clean_data.strategy);
//	printf("size of input : %d\n", clean_data.size);
//}

// void	display_stack(const t_stack *a, const t_stack *b)
// {
// 	t_stack	*atemp;
// 	t_stack	*btemp;
// 	int		aval;
// 	int		bval;

// 	atemp = (t_stack *) a;
// 	btemp = (t_stack *) b;
// 	printf("----------------\n    A    B\n----------------\n");
// 	while (atemp || btemp)
// 	{
// 		if (!atemp)
// 			aval = 0;
// 		else
// 			aval = atemp->value;
// 		if (!btemp)
// 			bval = 0;
// 		else
// 			bval = btemp->value;
// 		printf("    %d    %d\n", aval, bval);
// 		if (atemp)
// 			atemp = atemp->next;
// 		if (btemp)
// 			btemp = btemp->next;
// 	}
// }

//int	main(int ac, char **av)
//{
//	t_input		clean_data;
//	t_stack		*a;
//	t_stack		*b;
//	t_output	out;

//	a = NULL;
//	b = NULL;
//	if (ac == 1)
//		return (0);
//	check_space(av);
//	clean_data = parse_args(ac, av);
//	test_input(clean_data);
//	a = init_stack(clean_data);
//	if (a)
//	{
//		init_out(&clean_data, a, &out);
//		if (out.disorder > 0.0)
//			sort_stack(&a, &b, &out);
//		display_stack(a, b);
//		compute_total_ops(&out);
//		bench_output(out);
//	}
//	free_stack(&a);
//	free_stack(&b);
//	return (0);
//}
