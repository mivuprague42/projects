#include <unistd.h>

void    my_putnbr(long long n)
{
    char    digit;

    if (n == 0)
        return;
    digit = '0' + n % 10;
    my_putnbr(n / 10);
    write(1, &digit, 1);
}

void    ft_putnbr(int nb)
{
    long long    n;

    n = nb;
    if (n < 0)
    {
        write(1, "-", 1);
        my_putnbr(-n);
    }
    else if (n == 0)
        write(1, "0", 1);
    else
        my_putnbr(n);
}
