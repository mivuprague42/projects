#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    while (n-- && (*s1 || *s2))
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        s1++;
        s2++;
    }
    return (0);
}

int main(void)
{
    char s1[] = "hello";
    char s2[] = "hello";
    printf("%d\n", ft_strncmp(s1, s2, 10));
}
