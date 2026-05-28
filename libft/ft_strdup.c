/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:47:55 by kri-              #+#    #+#             */
/*   Updated: 2026/04/21 22:53:03 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*output;
	char	*src;

	l = 0;
	src = (char *)s;
	while (src[l])
		l++;
	output = (char *) malloc (l * sizeof (char) + 1);
	if (!output)
		return (0);
	l = 0;
	while (src[l])
	{
		output[l] = src[l];
		l++;
	}
	output[l] = '\0';
	return (output);
}
