/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 23:46:14 by meqian            #+#    #+#             */
/*   Updated: 2026/06/03 17:21:34 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_input(int ac, char **av)
{
	char	*tmp;
	char	**result;
	char	*joined_str;
	char	*space_str;
	int		i;

	joined_str = ft_strdup("");
	if (!joined_str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		space_str = ft_strjoin(av[i], " ");
		tmp = ft_strjoin(joined_str, space_str);
		free(joined_str);
		free(space_str);
		joined_str = tmp;
		i ++;
	}
	result = ft_split(joined_str, ' ');
	free(joined_str);
	return (result);
}

void	remove_flag(char **av, int index)
{
	free(av[index]);
	while (av[index])
	{
		av[index] = av[index + 1];
		index++;
	}
}

int	strategy_selector(char **av)
{
	int	i;
	int	strategy;

	i = 0;
	strategy = ADAPTIVE;
	while (av[i])
	{
		if (ft_strcmp(av[i], "--simple") == 0
			|| ft_strcmp(av[i], "--medium") == 0
			|| ft_strcmp(av[i], "--complex") == 0
			|| ft_strcmp(av[i], "--adaptive") == 0)
		{
			if (ft_strcmp(av[i], "--simple") == 0)
				strategy = SIMPLE;
			else if (ft_strcmp(av[i], "--medium") == 0)
				strategy = MEDIUM;
			else if (ft_strcmp(av[i], "--complex") == 0)
				strategy = COMPLEX;
			remove_flag(av, i);
		}
		else
			i ++;
	}
	return (strategy);
}

void	check_space(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
		{
			j ++;
		}
		if (av[i][j] == '\0')
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit (1);
		}
		i ++;
	}
}
