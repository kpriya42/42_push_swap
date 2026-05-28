/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:47:21 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 13:44:05 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s && (fd > 0))
	{
		write (fd, s, ft_strlen(s));
		write (fd, "\n", 1);
	}
	return ;
}

//int main (void)
//{
//	ft_putstr_fd("YELLow World!",1);
//	return 0;
//}