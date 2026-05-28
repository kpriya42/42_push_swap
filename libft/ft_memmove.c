/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:19:38 by kri-              #+#    #+#             */
/*   Updated: 2026/04/21 22:16:56 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdest;

	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (!psrc && !pdest)
		return (0);
	if (pdest < psrc)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	return (dest);
}
