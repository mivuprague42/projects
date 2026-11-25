#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*dup;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dup = malloc(src_len + 1);
	if (dup == NULL)
		return (NULL);
	dup[src_len--] = '\0';
	while (src_len >= 0)
	{
		dup[src_len] = src[src_len];
		src_len--;
	}
	return (dup);
}
