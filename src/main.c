/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:53:08 by meqian            #+#    #+#             */
/*   Updated: 2026/05/27 16:37:33 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_convert(char *av, char **splited_arry)
{
	long	num;

	if (!all_digit(av))
		error_exit(splited_arry);
	num = ft_atol(av);
	if (num > 2147483647 || num < -2147483648)
		error_exit(splited_arry);
	return ((int) num);
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

	if (ac == 1)
		return (0);
	check_space(av);
	clean_data = parse_args(ac, av);
	puts("-----------------------------");
	printf("bench mark : %d\n", clean_data.bench_mark);
	printf("strategy type : %d\n", clean_data.strategy);
	printf("size of input : %d\n", clean_data.size);
	int i = 0;
	while (i < clean_data.size)
	{
		printf("args unsorted order :%d\n", clean_data.numbers[i]);
		i ++;
	}
	puts("|||||||||||||||||||||||||||||");
	return (0);
}
