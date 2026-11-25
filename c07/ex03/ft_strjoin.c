#include <stdlib.h>

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	strs_size(int size, char **strs, char *sep)
{
	int	sz;
	int	i;
	int	j;

	if (size > 0)
		sz = (size - 1) * my_strlen(sep) + 1;
	else
		sz = 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			sz++;
		i++;
	}
	return (sz);
}

void	put_sep(char **str, char *sep)
{
	while (*sep)
		*(*str)++ = *sep++;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	char	*o_tmp;
	int		str_size;
	int		i;
	int		j;

	str_size = strs_size(size, strs, sep);
	o_tmp = malloc(str_size);
	if (!o_tmp)
		return (NULL);
	i = 0;
	tmp = o_tmp;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			*tmp++ = strs[i][j++];
		if (i < size - 1)
			put_sep(&tmp, sep);
		i++;
	}
	*tmp = '\0';
	return (o_tmp);
}
