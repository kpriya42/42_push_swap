/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:49:35 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 13:44:26 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		num[10];
	int			i;

	if (!(fd > 0))
		return ;
	i = 0;
	nb = n;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		num[i] = (nb % 10) + '0';
		i++;
		nb = nb / 10;
	}
	while (--i >= 0)
		write(fd, &num[i], 1);
}

//int main (void)
//{
//	ft_putnbr_fd (2147483647, 1);
//	return 0;
//}
