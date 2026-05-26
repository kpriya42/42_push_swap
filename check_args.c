/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:05:15 by meqian            #+#    #+#             */
/*   Updated: 2026/05/26 12:20:07 by meqian           ###   ########.fr       */
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


int	check_convert(char *av, char **splited_arry)
{
	
}