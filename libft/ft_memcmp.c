/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:07:54 by kri-              #+#    #+#             */
/*   Updated: 2026/04/20 19:33:36 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pstr1;
	unsigned char	*pstr2;
	size_t			i;

	pstr1 = (unsigned char *)s1;
	pstr2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (pstr1[i] == pstr2[i]))
		i++;
	if (i == n)
		return (0);
	return (pstr1[i] - pstr2[i]);
}
