/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:06:39 by kri-              #+#    #+#             */
/*   Updated: 2026/05/29 15:10:38 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bench_adaptive_output(t_output out, int fd)
{
	ft_putstr_fd("Adaptive / ", fd);
	if (out.disorder < 0.2)
		ft_putendl_fd("O(n²)", fd);
	else if (out.disorder < 0.5)
		ft_putendl_fd("O(n√n)", fd);
	else
		ft_putendl_fd("O(nlogn)", fd);
}

static void	bench_operations_output(t_output out, int fd)
{
	ft_putstr_fd("[bench] sa:   ", fd);
	ft_putnbr_fd(out.sa_count, fd);
	ft_putstr_fd("   sb:   ", fd);
	ft_putnbr_fd(out.sb_count, fd);
	ft_putstr_fd("   pa:   ", fd);
	ft_putnbr_fd(out.pa_count, fd);
	ft_putstr_fd("   pb:   ", fd);
	ft_putnbr_fd(out.pb_count, fd);
	ft_putstr_fd("\n[bench] ra:   ", fd);
	ft_putnbr_fd(out.ra_count, fd);
	ft_putstr_fd("   rb:   ", fd);
	ft_putnbr_fd(out.rb_count, fd);
	ft_putstr_fd("   rr:   ", fd);
	ft_putnbr_fd(out.rr_count, fd);
	ft_putstr_fd("   rra:   ", fd);
	ft_putnbr_fd(out.rra_count, fd);
	ft_putstr_fd("   rrb:   ", fd);
	ft_putnbr_fd(out.rrb_count, fd);
	ft_putstr_fd("   rrr:   ", fd);
	ft_putnbr_fd(out.rrr_count, fd);
}

void	bench_output(t_output out)
{
	int	fd;
	int	temp;

	fd = STDOUT_FILENO;
	temp = out.disorder * 100;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(temp, fd);
	ft_putstr_fd("%\n[bench] stratergy: ", fd);
	if (out.strategy == SIMPLE)
		ft_putendl_fd("Simple O(n²)", fd);
	else if (out.strategy == MEDIUM)
		ft_putendl_fd("Medium O(n√n)", fd);
	else if (out.strategy == COMPLEX)
		ft_putendl_fd("Complex O(nlogn)", fd);
	else
		bench_adaptive_output(out, fd);
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(out.total_count, fd);
	bench_operations_output(out, fd);
}
