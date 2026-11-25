#include <stdlib.h>

void	h_table_init(unsigned char *table, char *charset)
{
	int				i;

	table['\0'] = 1;
	i = 1;
	while (i < 256)
		table[i++] = 0;
	while (*charset)
		table[(unsigned char)*charset++] = 1;
}

int	count_words(char *str, unsigned char *h_table)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (1)
	{
		if (h_table[(unsigned char)*str])
		{
			if (is_word)
				count++;
			if (!*str)
				break ;
			is_word = 0;
		}
		else
			is_word = 1;
		str++;
	}
	return (count);
}

char	*process_string(char **str, unsigned char *h_table)
{
	int		str_len;
	int		i;
	char	*element;

	str_len = 0;
	while (**str && h_table[(unsigned char)**str])
		(*str)++;
	while (!h_table[(unsigned char)**str])
	{
		str_len++;
		(*str)++;
	}
	element = malloc(str_len + 1);
	if (!element)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		element[i] = *(*str - str_len + i);
		i++;
	}
	element[i] = '\0';
	return (element);
}

char	**ft_split(char *str, char *charset)
{
	unsigned char	h_table[256];
	int				words_count;
	int				i;
	char			**arr;

	h_table_init(h_table, charset);
	words_count = count_words(str, h_table);
	arr = malloc(sizeof(char *) * (words_count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		arr[i] = process_string(&str, h_table);
		if (!arr[i])
			return (NULL);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
