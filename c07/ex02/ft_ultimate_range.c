#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	size_t	size;
	size_t	int_max;
	size_t	i;

	*range = NULL;
	int_max = (unsigned int)-1 / 2;
	if (min >= max)
		return (0);
	size = (long long)max - (long long)min;
	if (size > int_max || size > (size_t)-1 / sizeof(int))
		return (-1);
	*range = malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = (int)((long long)min + (long long)i);
		i++;
	}
	return ((int)size);
}
