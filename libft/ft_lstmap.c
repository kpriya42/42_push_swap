/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:15:28 by kri-              #+#    #+#             */
/*   Updated: 2026/04/28 19:54:15 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*node;
	void	*content;

	if (!lst || !*f || !del)
		return (NULL);
	output = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del (content);
			ft_lstclear(&output, del);
			return (NULL);
		}
		ft_lstadd_back(&output, node);
		lst = lst->next;
	}
	return (output);
}
