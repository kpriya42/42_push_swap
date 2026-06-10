/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:50:55 by kri-              #+#    #+#             */
/*   Updated: 2026/06/10 12:14:17 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	inputlen;

	i = 0;
	if (!s)
		return (NULL);
	inputlen = ft_strlen(s);
	if (start >= inputlen)
		len = 0;
	else if (start + len > inputlen)
		len = inputlen - start;
	substring = (char *) malloc ((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len)
		substring[i++] = s[start++];
	substring[len] = '\0';
	return (substring);
}

//int main (void)
//{
//	//unsigned int start = 4294967295;
//	//unsigned long len = 18446744073709551615UL;
//	//printf ("%s\n",ft_substr("hola", 4294967295UL, 18446744073709551615UL));
//	printf ("%s\n",ft_substr("hola", 0, 18446744073709551615UL));
//	return 0;
//}