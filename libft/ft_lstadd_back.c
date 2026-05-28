/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:10:00 by kri-              #+#    #+#             */
/*   Updated: 2026/04/27 15:46:02 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function adds "new" node as the last node of the list pointed by "lst"
Algo :
	if given parameters are not valid ponters, then return NULL
	If given list "lst" is empty (i.e. first node is empty), 
	then assign "new" as the first (& only) node in the lst
	If given list "lst" is not empty. find last node of the list 
	and assign "new" as the new last node using "next" member.
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastelement;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastelement = ft_lstlast(*lst);
	lastelement->next = new;
}
