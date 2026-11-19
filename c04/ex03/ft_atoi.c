int ft_atoi(char *str)
{
    int sign;
    int res;

    sign = 1;
    res = 0;
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    while (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign *= -1;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + *str++ - '0';
    return (sign * res);
}
