/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivu <mivu@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 23:23:37 by mivu              #+#    #+#             */
/*   Updated: 2026/11/09 19:59:26 by mivu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(char *arr, int digit_1, int digit_2)
{
	arr[0] = '0' + digit_1 / 10;
	arr[1] = '0' + digit_1 % 10;
	arr[2] = '0' + digit_2 / 10;
	arr[3] = '0' + digit_2 % 10;

	write(1, arr, 2);
	write(1, " ", 1);
	write(1, &arr[2], 2);

	if (digit_1 + digit_2 == 98 + 99)
		write(1, "\n", 1);
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char arr[4];
	
	int digit_1;
	int digit_2;
	
	digit_1 = 0;
	while(digit_1 < 100)
	{

		digit_2 = digit_1 + 1;
		while(digit_2 < 100)
		{
			print_digits(arr, digit_1, digit_2);
			digit_2++;
		}
		digit_1++;
	}
}

int main(void)
{
	ft_print_comb2();
	return 0;
}
