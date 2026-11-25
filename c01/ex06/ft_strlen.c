int ft_strlen(char *str)
{
	int count = 0;
	char *c = str;
	while (*c != '\0')
	{
		count++;
		c++;
	}
	return count;
}
