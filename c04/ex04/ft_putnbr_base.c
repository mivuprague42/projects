#include <unistd.h>

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
        if (*base == '-' || *base == '+' || h_table[(unsigned char)*base])
            return (0);
        h_table[(unsigned char)*base] = 1;
        base++;
        system++;
    }
    return (system);
}

void    my_putnbr_base(unsigned int n, char *base, int system)
{
    int    digit;

    if (n == 0)
        return ;
    digit = n % system;
    my_putnbr_base(n / system, base, system);
    write(1, &base[digit], 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int             system;

    system = get_base_system(base);
    if (system < 2)
        return ;
    if (nbr < 0)
    {
        write(1, "-", 1);
        my_putnbr_base(-(unsigned int)nbr, base, system);
    }
    else if (nbr == 0)
        write(1, &base[0], 1);
    else
        my_putnbr_base(nbr, base, system);
}
