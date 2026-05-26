/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:53:08 by meqian            #+#    #+#             */
/*   Updated: 2026/05/26 18:39:21 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_input	parse_args(int ac, char **av)
{
	t_input	data;
	char	**splited_av;
	int		i;

	i = 0;
	splited_av = split_input(ac, av);
	if (!splited_av)
		exit(1);
	data.strategy = strategy_selector(av);
	data.size = 0;
	while (splited_av[data.size])
		data.size++;
	data.numbers = malloc(sizeof(int) * data.size);
	while (i < data.size)
	{
		data.numbers[i] = check_convert(splited_av[i], splited_av);
		i ++;
	}
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
	clean_data = parse_args(ac, av);
	printf("strategy type : %d\n", clean_data.strategy);
	printf("size of input : %d\n", clean_data.size);
	int i = 0;
	while (i < clean_data.size)
	{
		printf("args %d\n", clean_data.numbers[i]);
		i ++;
	}
	printf("strategy type : %d", clean_data.strategy);
	return (0);
}
