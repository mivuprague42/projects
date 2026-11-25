#include <unistd.h>

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);


void	print_int(int n)
{
	char	c;

	if (n >= 10)
		print_int(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

void	print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		print_str(par->str);
		print_int(par->size);
		write(1, "\n", 1);
		print_str(par->copy);
		par++;
	}
}
