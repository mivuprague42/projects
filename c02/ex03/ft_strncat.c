char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char    *o_dest;

    o_dest = dest;
    while (*dest)
        dest++;
    while (nb-- && *src)
        *dest++ = *src++;
    *dest = '\0';
    return (o_dest);
}
