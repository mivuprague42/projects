#include <unistd.h>

int main(int argc, char **argv)
{
	int	len;

	while (--argc)
	{
		len = 0;
		while (argv[argc][len])
			len++;
		write(1, argv[argc], len);
		write(1, "\n", 1);
	}
	return (0);
}
