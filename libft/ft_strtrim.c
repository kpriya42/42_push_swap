/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:54:40 by kri-              #+#    #+#             */
/*   Updated: 2026/04/22 19:55:40 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	foundchar(char const *set, char ch)
{
	char	*charset;

	charset = (char *)set;
	while (*charset)
	{
		if (*charset == ch)
			return (1);
		charset++;
	}
	return (0);
}

static char	*trim(char *str, char const *set)
{
	char	*output;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && foundchar(set, str[start]))
		start++;
	while (start <= end && str[end] && foundchar(set, str[end]))
		end--;
	output = malloc(end - start + 2);
	if (!output)
		return (NULL);
	while (start <= end)
		output[i++] = str[start++];
	output[i] = '\0';
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*output;

	if (!s1)
		return (NULL);
	str = (char *)s1;
	if (*str == '\0')
	{
		output = malloc(sizeof (char));
		if (!output)
			return (NULL);
		else
		{
			output[0] = '\0';
			return (output);
		}
	}
	output = trim(str, set);
	return (output);
}
