/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:53:08 by meqian            #+#    #+#             */
/*   Updated: 2026/05/26 11:51:48 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_input	*parse_args(int ac, char **av)
{
	
}

int	main(int ac, char **av)
{
	t_input	clean_data;

	if (ac == 1)
		return (0);
	clean_data = parse_args(ac, av);

	return (0);
}