void    init_hash_table(unsigned char *table)
{
    int i;

    i = 0;
    while (i < 256)
        table[i++] = 0;
}

int get_base_system(char *base)
{
    unsigned char   h_table[256];
    int             system;

    init_hash_table(h_table);
    system = 0;
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
        system++;
    }
    return (system);
}

int	get_number(char c, char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int sign;
    int res;
    int	system;
    int n;

    sign = 1;
    res = 0;
    system = get_base_system(base);
    if (system < 2)
    	return (0);
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    while (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign *= -1;
    while (*str)
    {
    	n = get_number(*str, base);
     	if (n < 0)
      		break ;
	    res = res * system + n;
		str++;
    }
    return (sign * res);
}
