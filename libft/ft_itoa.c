/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:06:56 by kri-              #+#    #+#             */
/*   Updated: 2026/04/27 17:32:55 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*createstring(int numlen, char *num)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc (numlen + 1 * sizeof(char));
	if (!output)
		return (NULL);
	output[numlen] = '\0';
	while (numlen--)
	{
		output[numlen] = num[i];
		i++;
	}
	return (output);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		num[11];
	int			i;

	nb = n;
	i = 0;
	if (n == 0)
		num[i++] = '0';
	if (n < 0)
		nb = nb * (-1);
	while (nb > 0)
	{
		num[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		num[i++] = '-';
	return (createstring(i, num));
}

//int main (void)
//{
//	//printf("%s\n", ft_itoa(12345));
//	//printf("%s\n", ft_itoa(-12345));
//	//printf("%s\n", ft_itoa(2147483647));
//	//printf("%s\n", ft_itoa(0));
//	printf("%s\n", ft_itoa(-2147483648));
//	return 0;
//}
