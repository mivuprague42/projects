#include <stdio.h>

unsigned int    my_strlen(char *str)
{
    unsigned int    len;

    len = 0;
    while (*str++)
        len++;
    return (len);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    char            *o_dest;
    char            *o_src;
    unsigned int    dest_len;
    unsigned int    src_len;
    unsigned int    n;

    o_dest = dest;
    o_src = src;
    n = size;
    while (n-- && *dest)
        dest++;
    dest_len = dest - o_dest;
    src_len = my_strlen(src);
    n = size - dest_len;
    if (!n--)
        return (dest_len + src_len);
    while (*src && n--)
        *dest++ = *src++;
    *dest = '\0';
    return (dest_len + src_len);
}

int main(void)
{
    char dest[10] = "Hello";
    char src[] = "World";

    printf("%u\n", ft_strlcat(dest, src, 10));
    printf("%s\n", dest);
}
