/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:36:55 by kri-              #+#    #+#             */
/*   Updated: 2026/06/03 18:38:17 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;
	int		index;

	current = head;
	while (current)
	{
		index = 0;
		next = head;
		while (next)
		{
			if (next->value < current->value)
				index++;
			next = next->next;
		}
		current->index = index;
		current = current->next;
	}
}

static t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*init_stack(t_input input)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*new_node;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (i < input.size)
	{
		new_node = create_new_node(input.numbers[i]);
		if (!new_node)
			return (NULL);
		if (!head)
			head = new_node;
		else
		{
			tail->next = new_node;
			new_node->prev = tail;
		}
		tail = new_node;
		i++;
	}
	assign_indexes(head);
	return (head);
}

void	free_stack(t_stack **head)
{
	t_stack	*temp;

	if (!head)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

void	init_out(t_input *input, t_stack *a, t_output *out)
{
	printf ("inside inti out\n");
	out->strategy = input->strategy;
	out->disorder = compute_disorder(a);
	out->sa_count = 0;
	out->sb_count = 0;
	out->ss_count = 0;
	out->ra_count = 0;
	out->rb_count = 0;
	out->rr_count = 0;
	out->rra_count = 0;
	out->rrb_count = 0;
	out->rrr_count = 0;
	out->pa_count = 0;
	out->pb_count = 0;
	out->total_count = 0;
	printf ("disorder = %f\n", out->disorder);
}
