/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:54:36 by kri-              #+#    #+#             */
/*   Updated: 2026/04/20 19:04:07 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pstr;

	pstr = (unsigned char *)s;
	while (n--)
	{
		if (*pstr == (unsigned char )c)
			return (pstr);
		pstr++;
	}
	return (0);
}
