/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:03:27 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 13:45:16 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*pstr;
	unsigned char	ch;

	pstr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (*pstr != ch && *pstr != '\0')
		pstr++;
	if (*pstr == ch)
		return ((char *)pstr);
	return (0);
}
