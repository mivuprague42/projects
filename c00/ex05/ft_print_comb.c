/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivu <mivu@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 23:23:54 by mivu              #+#    #+#             */
/*   Updated: 2026/11/07 23:23:55 by mivu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char arr[3];
	for (char i = '0'; i <= '9'; i++)
	{
		arr[0] = i;
		for (char j = i + 1; j <= '9'; j++)
		{
			arr[1] = j;
			for (char k = j + 1; k <= '9'; k++)
			{
				arr[2] = k;
				write(1, arr, 3);
				if (i + j + k == '7' + '8' + '9')
					write(1, "\n", 1);
				else
					write(1, ", ", 2);
			}
		}
	}
}

int main(void)
{
	ft_print_comb();
	return 0;
}
