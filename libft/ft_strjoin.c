/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:35:27 by kri-              #+#    #+#             */
/*   Updated: 2026/04/22 18:22:52 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*output;
	size_t	i;

	if (!s1)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	output = malloc ((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!output)
		return (0);
	while (*str1)
		output[i++] = *str1++;
	while (*str2)
		output[i++] = *str2++;
	output[i] = '\0';
	return (output);
}
