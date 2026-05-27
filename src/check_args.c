/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:05:15 by meqian            #+#    #+#             */
/*   Updated: 2026/05/27 16:20:51 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int *arry, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arry[i] == arry[j])
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	all_digit(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i ++;
	if (av[i] == '\0')
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i ++;
	}
	return (1);
}

void	free_split(char **splited_arry)
{
	int	i;

	i = 0;
	if (!splited_arry)
		return ;
	while (splited_arry[i])
	{
		free(splited_arry[i]);
		i ++;
	}
	free(splited_arry);
}

void	error_exit(char **splited_arry)
{
	write (2, "Error\n", 6);
	free_split(splited_arry);
	exit (1);
}

int	check_bench(char **av)
{
	int	i;
	int	bench;

	i = 0;
	bench = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "--bench") == 0)
		{
			bench = 1;
			remove_flag(av, i);
		}
		else
			i ++;
	}
	return (bench);
}
