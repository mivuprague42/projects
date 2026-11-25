#include <stdlib.h>

int	get_base_system(char *base);
int	atoi_base(char *nbr, char *base, int system);

int	get_size(int n, int system)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= system;
		size++;
	}
	return (size);
}

char	*itoa_base(int n, char *base, int system)
{
	int				size;
	unsigned int	abs_n;
	char			*res;

	size = get_size(n, system);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
		abs_n = -(unsigned int)n;
	else
		abs_n = n;
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size--] = base[abs_n % system];
		abs_n /= system;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		f_system;
	int		t_system;
	int		n;
	char	*res;

	f_system = get_base_system(base_from);
	t_system = get_base_system(base_to);
	if (f_system < 2 || t_system < 2)
		return (NULL);
	n = atoi_base(nbr, base_from, f_system);
	res = itoa_base(n, base_to, t_system);
	return (res);
}
