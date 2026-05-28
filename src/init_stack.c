/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:36:55 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 17:24:32 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_new_node(int value, int stack_name)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	if (stack_name == STACK_B)
		node->value = 0;
	else
		node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}


t_stack	*init_stack(t_input *input, int stack_name)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*new_node;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (i < input->size)
	{
		new_node = create_new_node(input->numbers[i], stack_name);
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
	return (head);
}
