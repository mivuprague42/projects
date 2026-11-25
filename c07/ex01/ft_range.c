#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*array;
	size_t		size;
	size_t		i;

	if (min >= max)
		return (NULL);
	size = (long long)max - (long long)min;
	if (size > (size_t)-1 / sizeof(int))
		return (NULL);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = (int)((long long)min + (long long)i);

		i++;
	}
	return (array);
}
