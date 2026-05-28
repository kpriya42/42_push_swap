/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:40:13 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 13:46:20 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*pstr;
	int				len;
	unsigned char	ch;

	pstr = (unsigned char *)s;
	len = 0;
	ch = (unsigned char) c;
	while (*pstr++)
		len++;
	pstr--;
	while (*pstr != ch && len--)
		pstr--;
	if (*pstr == ch)
		return ((char *)pstr);
	return (0);
}
