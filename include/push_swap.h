/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meqian <meqian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:26:07 by meqian            #+#    #+#             */
/*   Updated: 2026/05/27 16:09:20 by meqian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;

typedef struct s_input
{
	int	*numbers;
	int	size;
	int	strategy;
	int	bench_mark;
}	t_input;

void	sample_func(void);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		check_dup(int *arry, int size);
int		all_digit(char *av);
void	free_split(char **splited_arry);
void	error_exit(char **splited_arry);
int		check_convert(char *av, char **splited_arry);

char	**split_input(int ac, char **av);
void	remove_flag(char **av, int index);
int		strategy_selector(char **av);
long	ft_atol(char *str);
void	check_space(char **av);
int		check_bench(char **av);

t_input	parse_args(int ac, char **av);

#endif