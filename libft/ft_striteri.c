/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:10:05 by kri-              #+#    #+#             */
/*   Updated: 2026/04/26 18:32:50 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//void ft_test(unsigned int i, char *str)
//{
//	(void) i;
//	*str = *str - 32;
//}

//int	main(void)
//{
//	char str[3] = "abc";
//	ft_striteri(str, ft_test);
//	printf ("result = %s", str);
//	return 0;
//}
