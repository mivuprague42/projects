/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivu <mivu@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 01:23:38 by mivu              #+#    #+#             */
/*   Updated: 2026/11/10 01:25:50 by mivu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putnbr(int n)
{
	char	c;

	if (n == 0)
	{
		return ;
	}
	c = '0' + n % 10;
	my_putnbr(n / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int ab)
{
	if (ab == 0)
		write(1, "0", 1);
	else if (ab < 0)
	{
		write(1, "-", 1);
		my_putnbr(-ab);
	}
	else
		my_putnbr(ab);
	write(1, "\n", 1);
}

int	main(void)
{
	ft_putnbr(0);
	ft_putnbr(1300);
	ft_putnbr(429);
	ft_putnbr(-42);
	ft_putnbr(+1563);
	return (0);
}
