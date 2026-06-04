/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:26:07 by meqian            #+#    #+#             */
/*   Updated: 2026/06/04 18:36:04 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define FALSE 0
# define TRUE 1
# define LOW_DISORDER 0.2
# define HIGH_DISORDER 0.5

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_input
{
	int	*numbers;
	int	size;
	int	strategy;
	int	bench_mark;
}	t_input;

typedef struct s_output_helper
{
	int		strategy;
	double	disorder;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
	int		pa_count;
	int		pb_count;
	int		total_count;
}	t_output;

//input_validation
t_input	parse_args(int ac, char **av);
int		check_dup(int *arry, int size);
int		all_digit(char *av);
void	free_split(char **splited_arry);
void	error_exit(char **splited_arry);
int		check_convert(char *av, char **splited_arry);
char	**split_input(int ac, char **av);
void	remove_flag(char **av, int index);
int		strategy_selector(char **av);
void	check_space(char **av);
int		check_bench(char **av);

//Initializations
t_stack	*init_stack(t_input input);
void	free_stack(t_stack **head);
void	init_out(t_input *input, t_stack *a, t_output *out);

//push_swap.c
void	sort_stack(t_stack **a, t_stack **b, t_output *out);
double	compute_disorder(t_stack *head);
void	compute_total_ops(t_output *out);

void	insertion_based_sort(t_stack **a, t_stack **b, t_output *out);
//void	medium_sort(t_stack **a, t_stack **b, t_output *out);
void	radix_based_sort(t_stack **a, t_stack **b, t_output *out);

//operations	
void	sa(t_stack **a, t_output *out);
void	sb(t_stack **b, t_output *out);
void	ss(t_stack **a, t_stack **b, t_output *out);
void	pa(t_stack **a, t_stack **b, t_output *out);
void	pb(t_stack **a, t_stack **b, t_output *out);
void	ra(t_stack **a, t_output *out);
void	rb(t_stack **b, t_output *out);
void	rr(t_stack **a, t_stack **b, t_output *out);
void	rra(t_stack **a, t_output *out);
void	rrb(t_stack **b, t_output *out);
void	rrr(t_stack **a, t_stack **b, t_output *out);

//utils
t_stack	*find_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*find_max_index_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
int		get_node_pos(t_stack *stack, t_stack *target);
void	rotate_target_to_top(t_stack **stack, t_stack *target, t_output *out);

//bench mode output
void	bench_output(t_output out);

#endif