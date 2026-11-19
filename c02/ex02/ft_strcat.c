char    *ft_strcat(char *dest, char *src)
{
    char    *o_dest;

    o_dest = dest;
    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (o_dest);
}
