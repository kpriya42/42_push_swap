/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:45:34 by kri-              #+#    #+#             */
/*   Updated: 2026/04/26 18:08:43 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*output;

	if (!s || !f)
		return (NULL);
	output = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}

//char ft_test(unsigned int i, char ch)
//{
//	(void) i;
//	return ( ch - 32);
//}
//
//int	main(void)
//{
//	printf ("result = %s", ft_strmapi("abc", ft_test));
//	return 0;
//}
