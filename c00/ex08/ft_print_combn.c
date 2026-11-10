#include <unistd.h>

void	my_print_combn(char *arr, int index, int start, int sum, int size, int max)
{
	int i;

	if (index == size)
	{
		write(1, arr, size);
		if ( sum != max)
			write(1, ", ", 2);
		return ;
	}
	
	i = start;
	while (i <= 9)
	{
		arr[index] = '0' + i;
		my_print_combn(arr, index + 1, i + 1, sum + i, size, max);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int max;
	char arr[n];
	
	max = (n * (9 - n + 1 + 9)) / 2;
	my_print_combn(arr, 0, 0, 0, n, max);
}

int	main(void)
{
	ft_print_combn(9);
	return (0);
}
