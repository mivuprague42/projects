int	get_base_system(char *base)
{
	unsigned char	h_table[256];
	int				i;

	i = 0;
	while (i < 256)
		h_table[i++] = 0;
	i = 0;
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		else if ((*base >= 9 && *base <= 13) || *base == 32)
			return (0);
		else if (h_table[(unsigned char)*base])
			return (0);
		h_table[(unsigned char)*base] = 1;
		base++;
		i++;
	}
	return (i);
}

int	get_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *nbr, char *base, int system)
{
	int				sign;
	int				digit;
	unsigned int	res;

	sign = 1;
	res = 0;
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == 32)
		nbr++;
	while (*nbr == '+' || *nbr == '-')
		if (*nbr++ == '-')
			sign *= -1;
	while (*nbr)
	{
		digit = get_digit(*nbr++, base);
		if (digit < 0)
			break ;
		res = res * system + digit;
	}
	if (sign < 0)
		return ((int)-res);
	return ((int)res);
}
