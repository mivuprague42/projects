#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < argc)
	{
		key = argv[i];
		j = i;
		while (j > 1 && my_strcmp(key, argv[j - 1]) < 0)
		{
			argv[j] = argv[j - 1];
			argv[j - 1] = key;
			j--;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
