/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:53:08 by meqian            #+#    #+#             */
/*   Updated: 2026/05/28 19:54:14 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_operations(t_stack *a, t_stack *b);
void	display_stack(const t_stack *a, const t_stack *b);
void	test_input(t_input clean_data);

void	error_exit(char **splited_arry)
{
	write (2, "Error\n", 6);
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
		data.numbers[i] = check_convert(splited_av[i], splited_av);
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
	t_input	clean_data;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	check_space(av);
	clean_data = parse_args(ac, av);
	test_input(clean_data);
	a = init_stack(&clean_data, STACK_A);
	b = init_stack(&clean_data, STACK_B);
	display_stack(a, b);
	test_operations(a, b);
	return (0);
}
