#include <stdlib.h>

#include "ft_stock_str.h"

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*my_strcpy(int len, char *str)
{
	int		i;
	char	*tmp;

	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}

void	free_strings(struct s_stock_str *strings, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(strings[i++].copy);
	free(strings);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*strings;

	strings = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strings[i].size = my_strlen(av[i]);
		strings[i].str = av[i];
		strings[i].copy = my_strcpy(strings[i].size, av[i]);
		if (!strings[i].copy)
		{
			free_strings(strings, i);
			return (NULL);
		}
		i++;
	}
	strings[i].str = NULL;
	return (strings);
}
